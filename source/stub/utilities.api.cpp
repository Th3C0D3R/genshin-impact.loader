/**
 * \brief   utilities - api
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include "utilities.xor.hpp"

#include "utilities.api.hpp"
#include "utilities.strings.hpp"

#include <Windows.h>

//--------------------------------------------------------------------------------------------------

using namespace utilities;

//--------------------------------------------------------------------------------------------------

typedef struct _UNICODE_STRING
{
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY          InLoadOrderModuleList;
	LIST_ENTRY          InMemoryOrderModuleList;
	LIST_ENTRY          InInitializationOrderModuleList;
	void*               BaseAddress;
	void*               EntryPoint;
	ULONG               SizeOfImage;
	UNICODE_STRING      FullDllName;
	UNICODE_STRING      BaseDllName;
	ULONG               Flags;
	SHORT               LoadCount;
	SHORT               TlsIndex;
} LDR_MODULE, *PLDR_MODULE;

extern "C" { PLDR_MODULE get_module(); }

//--------------------------------------------------------------------------------------------------

void* get_address(HMODULE mod, char* proc)
{
	if (mod == nullptr || nullptr == proc)
	{

		return nullptr;
	}

	BYTE* base = (BYTE*)mod;
	IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)base;
	IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

	IMAGE_EXPORT_DIRECTORY* exp = (IMAGE_EXPORT_DIRECTORY*)(base + nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	DWORD* func = (DWORD*)(base + exp->AddressOfFunctions);
	DWORD* name = (DWORD*)(base + exp->AddressOfNames);
	WORD* ord = (WORD*)(base + exp->AddressOfNameOrdinals);

	for (DWORD i = 0; i < exp->NumberOfNames; ++i)
	{
		if (strings::imatch(proc, (char*)mod + name[i]))
		{
			return base + func[ord[i]];
		}
	}
	return nullptr;
}

bool find_address(wchar_t* name, HMODULE *dll_addr)
{

	PLDR_MODULE Lib = NULL;
	Lib = get_module();
	while (Lib->BaseDllName.Buffer != NULL)
	{
		if (strings::imatch(name, Lib->BaseDllName.Buffer))
		{
			*dll_addr = (HMODULE)Lib->BaseAddress;
			return true;
		}
		Lib = (PLDR_MODULE)Lib->InLoadOrderModuleList.Flink;
	}
	return false;
}

//--------------------------------------------------------------------------------------------------

FARPROC utilities::api::address(char* dll_name, char* proc_name)
{
	HMODULE module;
	wchar_t * target = strings::cstr2wstr(dll_name);
	if (find_address(target, &module) != false)
	{
		return (FARPROC)get_address(module, proc_name);
	}

}


