/**
 * \brief   stub - api
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include "utilities.api.hpp"
#include "utilities.xor.hpp"

#include <Windows.h>

//--------------------------------------------------------------------------------------------------

static HANDLE(*_CreateThread)(LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD) = (HANDLE(*)(LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("CreateThread").c_str());
static BOOL(*_DisableThreadLibraryCalls)(HMODULE) = (BOOL(*)(HMODULE))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("DisableThreadLibraryCalls").c_str());

static HMODULE(*_LoadLibraryExA)(LPCSTR, HANDLE, DWORD) = (HMODULE(*)(LPCSTR, HANDLE, DWORD))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("LoadLibraryExA").c_str());
static HMODULE(*_LoadLibraryW)(LPCWSTR) = (HMODULE(*)(LPCWSTR))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("LoadLibraryW").c_str());

static UINT(*_GetSystemDirectoryA)(LPSTR, UINT) = (UINT(*)(LPSTR, UINT))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("GetSystemDirectoryA").c_str());

static HMODULE(*_GetModuleHandleA)(LPCSTR) = (HMODULE(*)(LPCSTR))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("GetModuleHandleA").c_str());
static DWORD(*_GetModuleFileNameW)(HMODULE, LPWSTR, DWORD) = (DWORD(*)(HMODULE, LPWSTR, DWORD))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("GetModuleFileNameW").c_str());
static DWORD(*_GetFullPathNameW)(LPCWSTR, DWORD, LPWSTR, LPWSTR*) = (DWORD(*)(LPCWSTR, DWORD, LPWSTR, LPWSTR*))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("GetFullPathNameW").c_str());
static HANDLE(*_FindFirstFileW)(LPCWSTR, LPWIN32_FIND_DATAW) = (HANDLE(*)(LPCWSTR, LPWIN32_FIND_DATAW))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("FindFirstFileW").c_str());
static BOOL(*_FindNextFileW)(HANDLE, LPWIN32_FIND_DATAW) = (BOOL(*)(HANDLE, LPWIN32_FIND_DATAW))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("FindNextFileW").c_str());
static BOOL(*_FindClose)(HANDLE) = (BOOL(*)(HANDLE))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("FindClose").c_str());

static BOOL(*_FreeConsole)(void) = (BOOL(*)(void))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("FreeConsole").c_str());
static BOOL(*_CloseHandle)(HANDLE) = (BOOL(*)(HANDLE))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("CloseHandle").c_str());

static void(*_OutputDebugStringA)(LPCSTR) = (void(*)(LPCSTR))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("OutputDebugStringA").c_str());
static int(*_wvsprintfA)(LPSTR, LPCSTR, va_list) = (int(*)(LPSTR, LPCSTR, va_list))utilities::api::address(_xor_("user32.dll").c_str(), _xor_("wvsprintfA").c_str());
static LPSTR(*_lstrcpyA)(LPCSTR, LPCSTR) = (LPSTR(*)(LPCSTR, LPCSTR))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("lstrcpyA").c_str());
static wchar_t*(*_wcscpy)(wchar_t*, wchar_t const*) = (wchar_t*(*)(wchar_t*, wchar_t const*))utilities::api::address(_xor_("msvcrt.dll").c_str(), _xor_("wcscpy").c_str());
static wchar_t*(*_wcscat)(wchar_t*, wchar_t const*) = (wchar_t*(*)(wchar_t*, wchar_t const*))utilities::api::address(_xor_("msvcrt.dll").c_str(), _xor_("wcscat").c_str());

static BOOL(*_VirtualProtect)(LPVOID, SIZE_T, DWORD, PDWORD) = (BOOL(*)(LPVOID, SIZE_T, DWORD, PDWORD))utilities::api::address(_xor_("kernel32.dll").c_str(), _xor_("VirtualProtect").c_str());
static BOOLEAN(*_RemoveEntryList)(PLIST_ENTRY) = (BOOLEAN(*)(PLIST_ENTRY))utilities::api::address(_xor_("ntdll.dll").c_str(), _xor_("RemoveEntryList").c_str());



//--------------------------------------------------------------------------------------------------
