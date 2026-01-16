cmake_minimum_required(VERSION 3.10)
project(platform)

# Define library
add_library(platform INTERFACE)
target_compile_features(platform INTERFACE cxx_std_14)
target_include_directories(platform INTERFACE src/)
add_library(steinwurf::platform ALIAS platform)

# Install headers
install(
  DIRECTORY ./src/platform
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
  FILES_MATCHING
  PATTERN *.hpp)

# Is top level project?
if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  # Build executables
  add_executable(print_platform examples/print_platform/main.cpp)
  target_link_libraries(print_platform platform)

  # Enable CPU feature detection flags for print_platform
  # This allows the compiler to define feature macros like __AVX2__, __AVX__, etc.
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # GCC and Clang flags
    target_compile_options(print_platform PRIVATE
      -mmmx
      -msse
      -msse2
      -msse3
      -mssse3
      -msse4.1
      -msse4.2
      -mpclmul
      -mavx
      -mavx2
    )
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # MSVC flags - /arch:AVX2 enables AVX, AVX2, and all previous SSE features
    target_compile_options(print_platform PRIVATE /arch:AVX2)
  endif()

  enable_testing()
  add_test(print_platform print_platform)
endif()
