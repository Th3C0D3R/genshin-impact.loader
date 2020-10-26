/**
 * \brief   stub - dependencies
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#define CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <windowsx.h>

#include <cstdio>

#include <intrin.h>
#include <malloc.h>
#include <tchar.h>
#include <wincrypt.h>
#include <winnt.h>

#include <vector>
#include <string>
#include <iterator>

#define STRSAFE_NO_DEPRECATE
#include <strsafe.h>
#include <Psapi.h>

//--------------------------------------------------------------------------------------------------

#ifdef _WIN64
#pragma comment(lib, "Psapi.lib")
#else //x86
#pragma comment(lib, "Psapi.lib")
#endif

//--------------------------------------------------------------------------------------------------

