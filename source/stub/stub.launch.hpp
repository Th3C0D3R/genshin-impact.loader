/**
 * \brief   stub - launch
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------


#include "stub.api.hpp"
#include "stub.hide.hpp"
#include "stub.details.hpp"
#include "utilities.api.hpp"
#include "utilities.xor.hpp"
#include "utilities.logger.hpp"
#include "utilities.files.hpp"

//--------------------------------------------------------------------------------------------------

using namespace utilities;

namespace launch
{
	inline void load_about()
	{
		auto line_0 = _xor_("[" PROJECT_PARENT "] " PROJECT_NAME ", Build: " PROJECT_BUILD "\n");
		auto line_1 = _xor_("      " PROJECT_PARENT " Target: " PROJECT_TARGET "\n");
		auto line_2 = _xor_("      Author: " PROJECT_AUTHOR "\n");
		auto line_3 = _xor_("      Repository: " PROJECT_REPOSITORY "\n");
		auto line_4 = _xor_("      License: " PROJECT_LICENSE "\n");
		auto padding = _xor_("================================================================================\n");

		logger::debug(padding.c_str());
		logger::debug(line_0.c_str());
		logger::debug(line_1.c_str());
		logger::debug(line_2.c_str());
		logger::debug(line_3.c_str());
		logger::debug(line_4.c_str());
		logger::debug(padding.c_str());
	}

	inline void load_modifications()
	{
		wchar_t pattern[2048] = {};
		_wcscpy(pattern, _xor_(PROJECT_RESOURCES_PATH).c_str());
		_wcscat(pattern, _xor_(L"\\*").c_str());
		_wcscat(pattern, _xor_(L"\0").c_str());
		WIN32_FIND_DATA data;
		HANDLE h_find;
		if ((h_find = _FindFirstFileW(pattern, &data)) != INVALID_HANDLE_VALUE)
		{
			do
			{
				if (strings::imatch(files::get_extension(data.cFileName), _xor_(L".dll").c_str()))
				{
					wchar_t file_dir[80] = {};
					_wcscpy(file_dir, _xor_(PROJECT_RESOURCES_PATH).c_str());
					_wcscat(file_dir, data.cFileName);
					_wcscat(file_dir, _xor_(L"\0").c_str());
					WCHAR *file_ext = nullptr;
					WCHAR sz_dir[2048] = {};
					_GetFullPathNameW(file_dir, 2048, sz_dir, &file_ext);
					const HMODULE h_loaded_module = (HMODULE)_LoadLibraryW(sz_dir);
					if (h_loaded_module != nullptr)
					{
						hide::initialize(h_loaded_module);
#ifdef _DEBUG
						logger::debug("[" PROJECT_PARENT ", " PROJECT_NAME "] loaded 'extra' modification located at '%ls'\n", file_dir);
#endif
					}
					else
					{
#ifdef _DEBUG
						logger::debug(_xor_("[" PROJECT_PARENT ", " PROJECT_NAME "][ERROR!] failed to load a 'extra' modification located at '%ls'\n").c_str(), file_dir);
#endif
					}
				}
			} while (_FindNextFileW(h_find, &data) != 0);
			_FindClose(h_find);
#ifdef _DEBUG
			logger::debug(_xor_("[" PROJECT_PARENT ", " PROJECT_NAME "][SUCCESS!] finished loading modules.\n").c_str());
#endif
			return;
		}
#ifdef _DEBUG
		logger::debug(_xor_("[" PROJECT_PARENT ", " PROJECT_NAME "][ERROR!] failed to access 'extra' modifications folder\n").c_str());
#endif
	}
}
