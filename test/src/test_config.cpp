// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <platform/config.hpp>

#include <cstdint>
#include <map>
#include <string>

#include <gtest/gtest.h>

extern std::map<std::string, std::string> variable_map;

TEST(test_config, operating_system)
{
    std::string os = variable_map["os"];

#if defined(PLATFORM_LINUX)
#if defined(PLATFORM_ANDROID)
    EXPECT_EQ(os, "android");
#else
    EXPECT_EQ(os, "linux");
#endif
#elif defined(PLATFORM_WINDOWS)
    EXPECT_EQ(os, "windows");
#elif defined(PLATFORM_MAC)
    EXPECT_EQ(os, "mac");
#elif defined(PLATFORM_IOS)
    EXPECT_EQ(os, "ios");
#elif defined(PLATFORM_EMSCRIPTEN)
    EXPECT_EQ(os, "emscripten");
#elif defined(PLATFORM_FREEBSD)
    EXPECT_EQ(os, "freebsd");
#else
#error "Unknown operating system"
#endif
}

TEST(test_config, compiler_arch)
{
    std::string compiler = variable_map["compiler"];
    std::string arch = variable_map["arch"];

#if defined(PLATFORM_CLANG)
    EXPECT_EQ(compiler, "clang");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE);
#if defined(PLATFORM_CLANG_X86)
    EXPECT_TRUE(arch == "x86" || arch == "x86_64");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_X86);
#elif defined(PLATFORM_CLANG_ARM)
    EXPECT_EQ(arch, "arm");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_ARM);
#elif defined(PLATFORM_CLANG_MIPS)
    EXPECT_EQ(arch, "mips");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_MIPS);
#elif defined(PLATFORM_CLANG_ASMJS)
    EXPECT_EQ(arch, "asmjs");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_ASMJS);
#else
#error "Unknown CPU architecture"
#endif
#elif defined(PLATFORM_GCC)
    EXPECT_EQ(compiler, "gcc");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE);
#if defined(PLATFORM_GCC_X86)
    EXPECT_TRUE(arch == "x86" || arch == "x86_64");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_X86);
#elif defined(PLATFORM_GCC_ARM)
    EXPECT_EQ(arch, "arm");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_ARM);
#elif defined(PLATFORM_GCC_MIPS)
    EXPECT_EQ(arch, "mips");
    EXPECT_TRUE(PLATFORM_GCC_COMPATIBLE_MIPS);
#else
#error "Unknown CPU architecture"
#endif
#elif defined(PLATFORM_MSVC)
    EXPECT_EQ(compiler, "msvc");
#if defined(PLATFORM_MSVC_X86)
    EXPECT_TRUE(arch == "x86" || arch == "x86_64");
#elif defined(PLATFORM_MSVC_ARM)
    EXPECT_EQ(arch, "arm");
#else
#error "Unknown CPU architecture"
#endif
#else
#error "Unknown compiler"
#endif
}

TEST(Platform, check_architecture)
{
    std::string arch = variable_map["arch"];

#if defined(PLATFORM_X86)
    EXPECT_TRUE(arch == "x86" || arch == "x86_64");
#elif defined(PLATFORM_ARM)
    EXPECT_EQ(arch, "arm");
#elif defined(PLATFORM_MIPS)
    EXPECT_EQ(arch, "mips");
#elif defined(PLATFORM_ASMJS)
    EXPECT_EQ(arch, "asmjs");
#else
#error "Unknown CPU architecture"
#endif
}
