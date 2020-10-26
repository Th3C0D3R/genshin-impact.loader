/**
 * \brief   export
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

#ifndef DELAYIMP_INSECURE_WRITABLE_HOOKS
#define DELAYIMP_INSECURE_WRITABLE_HOOKS
#endif

//--------------------------------------------------------------------------------------------------

#include "stub.api.hpp"
#include "export.includes.hpp"
#include "utilities.xor.hpp"
#include "utilities.strings.hpp"

#include <Windows.h>
#include <Shlwapi.h>
#include <delayimp.h>

//--------------------------------------------------------------------------------------------------

#ifdef _WIN64
#pragma comment(lib, "delayimp.lib")
#else //x86
#pragma comment(lib, "delayimp.lib")
#endif

//--------------------------------------------------------------------------------------------------

FARPROC OnPreLoadLibrary(PDelayLoadInfo info)
{
	const auto dll_name = _xor_("hid.dll");
	if (utilities::strings::imatch((char*)info->szDll, (char*)dll_name.c_str()))
	{
		CHAR sz_path[MAX_PATH + 64];	
		DWORD count = _GetSystemDirectoryA(sz_path, MAX_PATH);
		if (!count || count > MAX_PATH)
		{
			return nullptr;
		}

		sz_path[count++] = '\\';
		_lstrcpyA(sz_path + count, dll_name.c_str());
		return reinterpret_cast<FARPROC>(_LoadLibraryExA(sz_path, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH));
	}
	return nullptr;
}

//--------------------------------------------------------------------------------------------------

extern "C" FARPROC WINAPI DelayLoadHook(unsigned dli_notify, PDelayLoadInfo info)
{

	switch (dli_notify)
	{
	case dliNotePreLoadLibrary:
	{
		return OnPreLoadLibrary(info);
	}
	default:
	case dliStartProcessing:
	case dliNotePreGetProcAddress:
	case dliFailLoadLib:
	case dliFailGetProc:
	case dliNoteEndProcessing:
	{
		break;
	}
	}
	return nullptr;
}


PfnDliHook __pfnDliNotifyHook2 = static_cast<PfnDliHook>(DelayLoadHook);