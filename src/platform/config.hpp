// Copyright (c) 2014 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

// Here we create a number of defines to make it easy to choose between
// different compilers, operatings systems and CPU architectures.
// Some information about the defines used can be found here:
// http://sourceforge.net/p/predef/wiki/Architectures/

// Detect operating systems
#if defined(__linux__)
    #define PLATFORM_LINUX
    #if defined(__ANDROID__)
        #define PLATFORM_ANDROID
    #endif
#elif defined(_WIN32)
    #define PLATFORM_WINDOWS
#elif defined(__APPLE__)
    // Detect iOS before MacOSX (__MACH__ is also defined for iOS)
    #if defined(IPHONE)
        #define PLATFORM_IOS
    #elif defined(__MACH__)
        #define PLATFORM_MAC
    #endif
#else
    #error "Unable to determine operating system"
#endif

// Detect compilers and CPU architectures
// Note: clang also defines __GNUC__ since it aims to be compatible with GCC.
// Therefore we need to check for __clang__ or __llvm__ first.
#if defined(__clang__) || defined(__llvm__)
    #define PLATFORM_CLANG
    #define PLATFORM_GCC_COMPATIBLE
    #if defined(__i386__) || defined(__x86_64__)
        #define PLATFORM_X86
        #define PLATFORM_CLANG_X86
        #define PLATFORM_GCC_COMPATIBLE_X86
    #elif defined(__arm__)
        #define PLATFORM_ARM
        #define PLATFORM_CLANG_ARM
        #define PLATFORM_GCC_COMPATIBLE_ARM
    #elif defined(__mips__)
        #define PLATFORM_MIPS
        #define PLATFORM_CLANG_MIPS
        #define PLATFORM_GCC_COMPATIBLE_MIPS
    #endif
#elif defined(__GNUC__)
    #define PLATFORM_GCC
    #define PLATFORM_GCC_COMPATIBLE
    #if defined(__i386__) || defined(__x86_64__)
        #define PLATFORM_X86
        #define PLATFORM_GCC_X86
        #define PLATFORM_GCC_COMPATIBLE_X86
    #elif defined(__arm__)
        #define PLATFORM_ARM
        #define PLATFORM_GCC_ARM
        #define PLATFORM_GCC_COMPATIBLE_ARM
    #elif defined(__mips__)
        #define PLATFORM_MIPS
        #define PLATFORM_GCC_MIPS
        #define PLATFORM_GCC_COMPATIBLE_MIPS
    #endif
#elif defined(_MSC_VER)
    #define PLATFORM_MSVC
    #if defined(_M_IX86) || defined(_M_X64)
        #define PLATFORM_X86
        #define PLATFORM_MSVC_X86
    #elif defined(_M_ARM) || defined(_M_ARMT)
        #define PLATFORM_ARM
        #define PLATFORM_MSVC_ARM
    #endif
#else
    #error "Unable to determine compiler"
#endif

// Define macros for supported CPU instruction sets
#if defined(PLATFORM_GCC_COMPATIBLE)
    #if defined(__MMX__)
        #define PLATFORM_MMX
    #endif
    #if defined(__SSE__)
        #define PLATFORM_SSE
    #endif
    #if defined(__SSE2__)
        #define PLATFORM_SSE2
    #endif
    #if defined(__SSE3__)
        #define PLATFORM_SSE3
    #endif
    #if defined(__SSSE3__)
        #define PLATFORM_SSSE3
    #endif
    #if defined(__SSE4_1__)
        #define PLATFORM_SSE41
    #endif
    #if defined(__SSE4_2__)
        #define PLATFORM_SSE42
    #endif
    #if defined(__PCLMUL__)
        #define PLATFORM_PCLMUL
    #endif
    #if defined(__AVX__)
        #define PLATFORM_AVX
    #endif
    #if defined(__AVX2__)
        #define PLATFORM_AVX2
    #endif
    #if defined(__ARM_NEON__)
        #define PLATFORM_NEON
    #endif
#elif defined(PLATFORM_MSVC)
    // MMX, SSE and SSE2 introduced in VS2003
    #if (_MSC_VER >= 1310)
        #define PLATFORM_MMX
        #define PLATFORM_SSE
        #define PLATFORM_SSE2
    #endif
    // SSE3 introduced in VS2005
    #if (_MSC_VER >= 1400)
        #define PLATFORM_SSE3
    #endif
    // SSSE3, SSE4.1, SSE4.2, PCLMUL introduced in VS2008
    #if (_MSC_VER >= 1500)
        #define PLATFORM_SSSE3
        #define PLATFORM_SSE41
        #define PLATFORM_SSE42
        #define PLATFORM_PCLMUL
    #endif
    // AVX and AVX2 introduced in VS2012
    #if (_MSC_VER >= 1700)
        #define PLATFORM_AVX
        #define PLATFORM_AVX2
    #endif
#endif
