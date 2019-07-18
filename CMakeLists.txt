cmake_minimum_required (VERSION 3.12)
project(platform)

add_library(platform INTERFACE)

target_include_directories(platform INTERFACE src/)
