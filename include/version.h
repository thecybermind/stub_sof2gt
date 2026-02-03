/*
Stub_SoF2GT - Example stub plugin for SOF2GT_QMM
Copyright 2025-2026
https://github.com/thecybermind/stub_sof2gt/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#ifndef STUB_SOF2GT_VERSION_H
#define STUB_SOF2GT_VERSION_H

#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

#define STUB_SOF2GT_VERSION_MAJOR	1
#define STUB_SOF2GT_VERSION_MINOR	0
#define STUB_SOF2GT_VERSION_REV	    0

#define STUB_SOF2GT_VERSION		STRINGIFY(STUB_SOF2GT_VERSION_MAJOR) "." STRINGIFY(STUB_SOF2GT_VERSION_MINOR) "." STRINGIFY(STUB_SOF2GT_VERSION_REV)

#if defined(_WIN32)
#define STUB_SOF2GT_OS             "Windows"
#ifdef _WIN64
#define STUB_SOF2GT_ARCH           "x86_64"
#else
#define STUB_SOF2GT_ARCH           "x86"
#endif
#elif defined(__linux__)
#define STUB_SOF2GT_OS             "Linux"
#ifdef __LP64__
#define STUB_SOF2GT_ARCH           "x86_64"
#else
#define STUB_SOF2GT_ARCH           "x86"
#endif
#endif

#define STUB_SOF2GT_VERSION_DWORD	STUB_SOF2GT_VERSION_MAJOR , STUB_SOF2GT_VERSION_MINOR , STUB_SOF2GT_VERSION_REV , 0
#define STUB_SOF2GT_COMPILE		    __TIME__ " " __DATE__
#define STUB_SOF2GT_BUILDER		    "Kevin Masterson"

#endif // STUB_SOF2GT_VERSION_H
