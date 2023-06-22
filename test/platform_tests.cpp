// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <CLI/CLI.hpp>
#include <cstdint>
#include <ctime>
#include <map>

#include <gtest/gtest.h>

std::map<std::string, std::string> variable_map;

GTEST_API_ int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    CLI::App app;

    app.add_option("--os", variable_map["os"],
                   "Operating system: [linux|windows|mac|ios|android]")
        ->default_val("");

    app.add_option("--compiler", variable_map["compiler"],
                   "Compiler: [gcc|clang|msvc]")
        ->default_val("");

    app.add_option("--arch", variable_map["arch"],
                   "Architecture: [x86|x86_64|arm|mips]")
        ->default_val("");

    CLI11_PARSE(app, argc, argv);

    return RUN_ALL_TESTS();
}