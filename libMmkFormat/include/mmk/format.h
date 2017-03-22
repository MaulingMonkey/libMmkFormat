/* Copyright 2017 MaulingMonkey

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef ZMMK_IG_FORMAT_H
#define ZMMK_IG_FORMAT_H

#include <stdio.h> // snprintf
#include <stdlib.h> // size_t

typedef struct {
	const char*		string;
	size_t			length;
} mmk_format_str_t;

/* ZMMK_FORMAT_IF_{MSVC,CLANG,GCC}: Shorthand to avoid unrecognized #pragma warnings on the 'wrong' compilers while leaving the warning enabled. */

#ifdef _MSC_VER
#define ZMMK_FORMAT_IF_MSVC(x) x
#else
#define ZMMK_FORMAT_IF_MSVC(x)
#endif

#ifdef __clang__
#define ZMMK_FORMAT_IF_CLANG(x) x
#else
#define ZMMK_FORMAT_IF_CLANG(x)
#endif

#ifdef __GNUC__
#define ZMMK_FORMAT_IF_GCC(x) x
#else
#define ZMMK_FORMAT_IF_GCC(x)
#endif

/* MMK_FORMAT_TRUNC(name, size, format, ...): Shorthand to create a fixed length buffer & snprintf safely on it without redundancy. -------------*/
#define MMK_FORMAT_TRUNC(name, size, ...)                                                                                                         \
	char name [ size ];                                                                                                                           \
	ZMMK_FORMAT_IF_MSVC( __pragma(warning(push))           __pragma(warning(error: 4473 4474 4475 4476 4477 4478 4774 4775 4776 4777 4778)) )     \
	ZMMK_FORMAT_IF_CLANG( _Pragma("clang diagnostic push"); _Pragma("clang diagnostic error \"-Wformat\"");                                 )     \
	ZMMK_FORMAT_IF_GCC(   _Pragma("GCC diagnostic push");   _Pragma("GCC diagnostic error \"-Wformat\"");                                   )     \
	mmk_format_str_t name ## _str = { name, (size_t)snprintf(name, sizeof(name), __VA_ARGS__) };                                                  \
	ZMMK_FORMAT_IF_GCC(   _Pragma("GCC diagnostic pop");   )                                                                                      \
	ZMMK_FORMAT_IF_CLANG( _Pragma("clang diagnostic pop"); )                                                                                      \
	ZMMK_FORMAT_IF_MSVC( __pragma(warning(pop))            )                                                                                      \
	((void)name ## _str) /* ; */                                                                                                                  \
/* ----------------------------------------------------------------------------------------------------------------------------------------------*/

#endif /* ndef ZMMK_IG_FORMAT_H */
