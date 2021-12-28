/*BEGIN_LEGAL 
Intel Open Source License 

Copyright (c) 2002-2017 Intel Corporation. All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */
/// @file xed-cpuid-bit-enum.h

// This file was automatically generated.
// Do not edit this file.

#if !defined(XED_CPUID_BIT_ENUM_H)
# define XED_CPUID_BIT_ENUM_H
#include "xed-common-hdrs.h"
typedef enum {
  XED_CPUID_BIT_INVALID,
  XED_CPUID_BIT_ADOXADCX,
  XED_CPUID_BIT_AES,
  XED_CPUID_BIT_AVX,
  XED_CPUID_BIT_AVX2,
  XED_CPUID_BIT_AVX512BW,
  XED_CPUID_BIT_AVX512CD,
  XED_CPUID_BIT_AVX512DQ,
  XED_CPUID_BIT_AVX512ER,
  XED_CPUID_BIT_AVX512F,
  XED_CPUID_BIT_AVX512IFMA,
  XED_CPUID_BIT_AVX512PF,
  XED_CPUID_BIT_AVX512VBMI,
  XED_CPUID_BIT_AVX512VL,
  XED_CPUID_BIT_AVX512_4FMAPS,
  XED_CPUID_BIT_AVX512_4VNNIW,
  XED_CPUID_BIT_AVX512_VPOPCNTDQ,
  XED_CPUID_BIT_BMI1,
  XED_CPUID_BIT_BMI2,
  XED_CPUID_BIT_CET,
  XED_CPUID_BIT_CLFLUSH,
  XED_CPUID_BIT_CLFLUSHOPT,
  XED_CPUID_BIT_CLWB,
  XED_CPUID_BIT_CMPXCHG16B,
  XED_CPUID_BIT_F16C,
  XED_CPUID_BIT_FMA,
  XED_CPUID_BIT_FXSAVE,
  XED_CPUID_BIT_INTEL64,
  XED_CPUID_BIT_INTELPT,
  XED_CPUID_BIT_INVPCID,
  XED_CPUID_BIT_LAHF,
  XED_CPUID_BIT_LZCNT,
  XED_CPUID_BIT_MOVEBE,
  XED_CPUID_BIT_MPX,
  XED_CPUID_BIT_OSPKU,
  XED_CPUID_BIT_OSXSAVE,
  XED_CPUID_BIT_PCLMULQDQ,
  XED_CPUID_BIT_PKU,
  XED_CPUID_BIT_POPCNT,
  XED_CPUID_BIT_PREFETCHW,
  XED_CPUID_BIT_PREFETCHWT1,
  XED_CPUID_BIT_RDRAND,
  XED_CPUID_BIT_RDSEED,
  XED_CPUID_BIT_RDTSCP,
  XED_CPUID_BIT_RDWRFSGS,
  XED_CPUID_BIT_RTM,
  XED_CPUID_BIT_SGX,
  XED_CPUID_BIT_SHA,
  XED_CPUID_BIT_SMAP,
  XED_CPUID_BIT_SMX,
  XED_CPUID_BIT_SSE,
  XED_CPUID_BIT_SSE2,
  XED_CPUID_BIT_SSE3,
  XED_CPUID_BIT_SSE4,
  XED_CPUID_BIT_SSE42,
  XED_CPUID_BIT_SSSE3,
  XED_CPUID_BIT_VMX,
  XED_CPUID_BIT_XSAVE,
  XED_CPUID_BIT_XSAVEC,
  XED_CPUID_BIT_XSAVEOPT,
  XED_CPUID_BIT_XSAVES,
  XED_CPUID_BIT_LAST
} xed_cpuid_bit_enum_t;

/// This converts strings to #xed_cpuid_bit_enum_t types.
/// @param s A C-string.
/// @return #xed_cpuid_bit_enum_t
/// @ingroup ENUM
XED_DLL_EXPORT xed_cpuid_bit_enum_t str2xed_cpuid_bit_enum_t(const char* s);
/// This converts strings to #xed_cpuid_bit_enum_t types.
/// @param p An enumeration element of type xed_cpuid_bit_enum_t.
/// @return string
/// @ingroup ENUM
XED_DLL_EXPORT const char* xed_cpuid_bit_enum_t2str(const xed_cpuid_bit_enum_t p);

/// Returns the last element of the enumeration
/// @return xed_cpuid_bit_enum_t The last element of the enumeration.
/// @ingroup ENUM
XED_DLL_EXPORT xed_cpuid_bit_enum_t xed_cpuid_bit_enum_t_last(void);
#endif
