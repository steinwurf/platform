// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <boost/program_options.hpp>
#include <cstdint>
#include <ctime>

#include <gtest/gtest.h>

boost::program_options::variables_map variable_map;

GTEST_API_ int main(int argc, char** argv)
{
    namespace po = boost::program_options;

    testing::InitGoogleTest(&argc, argv);

    po::options_description options;
    options.add_options()("os", po::value<std::string>()->default_value(""),
                          "Operating system: [linux|windows|mac|ios|android]")(
        "compiler", po::value<std::string>()->default_value(""),
        "Compiler: [gcc|clang|msvc]")(
        "arch", po::value<std::string>()->default_value(""),
        "Architecture: [x86|x86_64|arm|mips]");

    po::store(po::parse_command_line(argc, argv, options), variable_map);
    po::notify(variable_map);

    return RUN_ALL_TESTS();
}
