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

  enable_testing()
  add_test(print_platform print_platform)
endif()
