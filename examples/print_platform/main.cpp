// Copyright (c) 2013 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#include <iostream>

#include <platform/config.hpp>

int main()
{
    // Operating systems
    std::cout << "PLATFORM_LINUX ";
#if defined(PLATFORM_LINUX)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_ANDROID ";
#if defined(PLATFORM_ANDROID)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_WINDOWS ";
#if defined(PLATFORM_WINDOWS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_WINDOWS_64 ";
#if defined(PLATFORM_WINDOWS_64)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_WINDOWS_32 ";
#if defined(PLATFORM_WINDOWS_32)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_WINDOWS_PHONE ";
#if defined(PLATFORM_WINDOWS_PHONE)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_IOS ";
#if defined(PLATFORM_IOS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_MAC ";
#if defined(PLATFORM_MAC)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_EMSCRIPTEN ";
#if defined(PLATFORM_EMSCRIPTEN)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_FREEBSD ";
#if defined(PLATFORM_FREEBSD)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    // Compilers
    std::cout << "PLATFORM_CLANG ";
#if defined(PLATFORM_CLANG)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC ";
#if defined(PLATFORM_GCC)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_COMPATIBLE ";
#if defined(PLATFORM_GCC_COMPATIBLE)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_MSVC ";
#if defined(PLATFORM_MSVC)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    // Architectures
    std::cout << "PLATFORM_X86 ";
#if defined(PLATFORM_X86)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_ARM ";
#if defined(PLATFORM_ARM)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_MIPS ";
#if defined(PLATFORM_MIPS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_ASMJS ";
#if defined(PLATFORM_ASMJS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    // Compiler + Architecture combinations
    std::cout << "PLATFORM_CLANG_X86 ";
#if defined(PLATFORM_CLANG_X86)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_CLANG_ARM ";
#if defined(PLATFORM_CLANG_ARM)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_CLANG_MIPS ";
#if defined(PLATFORM_CLANG_MIPS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_CLANG_ASMJS ";
#if defined(PLATFORM_CLANG_ASMJS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_X86 ";
#if defined(PLATFORM_GCC_X86)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_ARM ";
#if defined(PLATFORM_GCC_ARM)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_MIPS ";
#if defined(PLATFORM_GCC_MIPS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_MSVC_X86 ";
#if defined(PLATFORM_MSVC_X86)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_MSVC_ARM ";
#if defined(PLATFORM_MSVC_ARM)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_COMPATIBLE_X86 ";
#if defined(PLATFORM_GCC_COMPATIBLE_X86)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_COMPATIBLE_ARM ";
#if defined(PLATFORM_GCC_COMPATIBLE_ARM)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_COMPATIBLE_MIPS ";
#if defined(PLATFORM_GCC_COMPATIBLE_MIPS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_GCC_COMPATIBLE_ASMJS ";
#if defined(PLATFORM_GCC_COMPATIBLE_ASMJS)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    // CPU instruction sets
    std::cout << "PLATFORM_MMX ";
#if defined(PLATFORM_MMX)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_SSE ";
#if defined(PLATFORM_SSE)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_SSE2 ";
#if defined(PLATFORM_SSE2)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_SSE3 ";
#if defined(PLATFORM_SSE3)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_SSSE3 ";
#if defined(PLATFORM_SSSE3)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_SSE41 ";
#if defined(PLATFORM_SSE41)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_SSE42 ";
#if defined(PLATFORM_SSE42)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_PCLMUL ";
#if defined(PLATFORM_PCLMUL)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_AVX ";
#if defined(PLATFORM_AVX)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_AVX2 ";
#if defined(PLATFORM_AVX2)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    std::cout << "PLATFORM_NEON ";
#if defined(PLATFORM_NEON)
    std::cout << "1";
#else
    std::cout << "0";
#endif
    std::cout << std::endl;

    return 0;
}
