cmake_minimum_required (VERSION 3.10)
project(platform)

file(GLOB platform_headers ./src/platform/*.hpp)

add_library(platform INTERFACE)
add_library(steinwurf::platform ALIAS platform)

target_include_directories(platform INTERFACE src/)

install(FILES ${platform_headers} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/platform)
