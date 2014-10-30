// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <cstdint>
#include <string>
#include <gtest/gtest.h>
#include <boost/program_options.hpp>

#include <platform/config.hpp>

boost::program_options::variables_map variable_map;

TEST(Platform, check_operating_system)
{
    std::string os = variable_map["os"].as<std::string>();

#if defined(PLATFORM_LINUX)
    #if defined(PLATFORM_ANDROID)
        EXPECT_TRUE(os == "android");
    #else
        EXPECT_TRUE(os == "linux");
    #endif
#elif defined(PLATFORM_WINDOWS)
    EXPECT_TRUE(os == "windows");
#elif defined(PLATFORM_MAC)
    EXPECT_TRUE(os == "mac");
#elif defined(PLATFORM_IOS)
    EXPECT_TRUE(os == "ios");
#elif defined(PLATFORM_BROWSER)
    EXPECT_TRUE(os == "browser");
#else
    #error "Undefined operating system"
#endif
}

TEST(Platform, check_compiler)
{
    std::string compiler = variable_map["compiler"].as<std::string>();
    std::string arch = variable_map["arch"].as<std::string>();

#if defined(PLATFORM_CLANG)
    EXPECT_TRUE(compiler == "clang");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE);
    #if defined(PLATFORM_CLANG_X86)
        EXPECT_TRUE(arch == "x86" || arch == "x86_64");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_X86);
    #elif defined(PLATFORM_CLANG_ARM)
        EXPECT_TRUE(arch == "arm");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_ARM);
    #elif defined(PLATFORM_CLANG_MIPS)
        EXPECT_TRUE(arch == "mips");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_MIPS);
    #elif defined(PLATFORM_CLANG_ASMJS)
        EXPECT_TRUE(arch == "asmjs");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_ASMJS);
    #else
        #error "Undefined CPU architecture"
    #endif
#elif defined(PLATFORM_GCC)
    EXPECT_TRUE(compiler == "gcc");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE);
    #if defined(PLATFORM_GCC_X86)
        EXPECT_TRUE(arch == "x86" || arch == "x86_64");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_X86);
    #elif defined(PLATFORM_GCC_ARM)
        EXPECT_TRUE(arch == "arm");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_ARM);
    #elif defined(PLATFORM_GCC_MIPS)
        EXPECT_TRUE(arch == "mips");
        EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_MIPS);
    #else
        #error "Undefined CPU architecture"
    #endif
#elif defined(PLATFORM_MSVC)
    EXPECT_TRUE(compiler == "msvc");
    #if defined(PLATFORM_MSVC_X86)
        EXPECT_TRUE(arch == "x86" || arch == "x86_64");
    #elif defined(PLATFORM_MSVC_ARM)
        EXPECT_TRUE(arch == "arm");
    #else
        #error "Undefined CPU architecture"
    #endif
#else
    #error "Undefined compiler"
#endif
}

TEST(Platform, check_architecture)
{
    std::string arch = variable_map["arch"].as<std::string>();

#if defined(PLATFORM_X86)
    EXPECT_TRUE(arch == "x86" || arch == "x86_64");
#elif defined(PLATFORM_ARM)
    EXPECT_TRUE(arch == "arm");
#elif defined(PLATFORM_MIPS)
    EXPECT_TRUE(arch == "mips");
#elif defined(PLATFORM_ASMJS)
    EXPECT_TRUE(arch == "ASMJS");
#else
    #error "Undefined CPU architecture"
#endif
}


GTEST_API_ int main(int argc, char** argv)
{
    namespace po = boost::program_options;

    testing::InitGoogleTest(&argc, argv);

    po::options_description options;
    options.add_options()
        ("os", po::value<std::string>()->default_value(""),
         "Operating system: [linux|windows|mac|ios|android]")
        ("compiler", po::value<std::string>()->default_value(""),
         "Compiler: [gcc|clang|msvc]")
        ("arch", po::value<std::string>()->default_value(""),
         "Architecture: [x86|x86_64|arm|mips]");

    po::store(po::parse_command_line(argc, argv, options), variable_map);
    po::notify(variable_map);

    return RUN_ALL_TESTS();
}
