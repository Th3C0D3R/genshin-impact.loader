/**
 * \brief   stub - hide
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include "stub.hide.hpp"
#include "stub.api.hpp"

#include <tchar.h>
#include <TlHelp32.h>
#include <intrin.h>

#include "ntdll/ntdll.h"

//--------------------------------------------------------------------------------------------------

#ifndef _WIN64
#pragma comment(lib,"ntdll/ntdll_x86.lib")
#else
#pragma comment(lib,"ntdll/ntdll_x64.lib")
#endif

//--------------------------------------------------------------------------------------------------

inline PVOID get_process_peb()
{
#ifdef _WIN64
	return (PVOID)__readgsqword(0x60);
#else
	return (PVOID)__readfsdword(0x30);
#endif
}

inline bool hide_in_load_order_links(HMODULE dll_base)
{
	const PPEB peb = (PPEB)get_process_peb();

	bool status = false;

	PLIST_ENTRY order_module_tail = nullptr;
	PLDR_DATA_TABLE_ENTRY pLdrDataEntry = nullptr;
	PLIST_ENTRY order_module_head = order_module_tail = peb->Ldr->InLoadOrderModuleList.Blink;

	do
	{
		pLdrDataEntry = (PLDR_DATA_TABLE_ENTRY)CONTAINING_RECORD(order_module_head, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);

		if (pLdrDataEntry->DllBase == nullptr)
		{
			break;
		}
		if (pLdrDataEntry->DllBase == dll_base)
		{
			_RemoveEntryList(order_module_head);
			status = true;
		}

		order_module_head = order_module_head->Blink;

	} while (order_module_head != order_module_tail);

	return status;
}

inline bool hide_in_memory_order_links(HMODULE dll_base)
{
	const PPEB peb = (PPEB)get_process_peb();

	bool status = false;

	PLIST_ENTRY order_module_tail = nullptr;
	PLIST_ENTRY order_module_head = order_module_tail = peb->Ldr->InMemoryOrderModuleList.Blink;

	do
	{
		PLDR_DATA_TABLE_ENTRY p_ldr_data_entry = (PLDR_DATA_TABLE_ENTRY)CONTAINING_RECORD(order_module_head, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);

		if (p_ldr_data_entry->DllBase == nullptr)
		{
			break;
		}

		if (p_ldr_data_entry->DllBase == dll_base)
		{
			_RemoveEntryList(order_module_head);
			status = true;
		}

		order_module_head = order_module_head->Blink;

	} while (order_module_head != order_module_tail);

	return status;
}

inline bool hide_in_initialization_order_links(HMODULE dll_base)
{
	const PPEB peb = (PPEB)get_process_peb();

	bool status = false;

	PLIST_ENTRY order_module_tail = nullptr;
	PLDR_DATA_TABLE_ENTRY pLdrDataEntry = nullptr;
	PLIST_ENTRY order_module_head = order_module_tail = peb->Ldr->InInitializationOrderModuleList.Blink;

	do
	{
		pLdrDataEntry = (PLDR_DATA_TABLE_ENTRY)CONTAINING_RECORD(order_module_head, LDR_DATA_TABLE_ENTRY, InInitializationOrderLinks);

		if (pLdrDataEntry->DllBase == nullptr)
		{
			break;
		}

		if (pLdrDataEntry->DllBase == dll_base)
		{
			_RemoveEntryList(order_module_head);
			status = true;
		}

		order_module_head = order_module_head->Blink;

	} while (order_module_head != order_module_tail);
	return status;
}

bool erase_headers(HMODULE dll_base)
{
	DWORD old_protection;
	bool status = _VirtualProtect((LPVOID)dll_base, 1000, PAGE_READWRITE, &old_protection);
	memset(dll_base, 0,1000);
	status = _VirtualProtect((LPVOID)dll_base, 1000, old_protection, &old_protection);
	return true;
}




//--------------------------------------------------------------------------------------------------


bool hide::initialize(HMODULE dll_base)
{
	return erase_headers(dll_base);
		//hide_in_load_order_links(dll_base) &&			 // needs work; error will send to uspider.yuanshen.com/fileupload	 
		//hide_in_memory_order_links(dll_base) &&		 // needs work; error will send to uspider.yuanshen.com/fileupload 
		//hide_in_initialization_order_links(dll_base);  // needs work; error will send to uspider.yuanshen.com/fileupload
		   
}
