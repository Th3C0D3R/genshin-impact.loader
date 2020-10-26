/**
 * \brief   stub
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#include "utilities.api.hpp"
#include "utilities.xor.hpp"
#include "utilities.files.hpp"
#include "utilities.logger.hpp"

#include "stub.api.hpp"
#include "stub.launch.hpp"
#include "stub.dependencies.hpp"

#include "export.hpp"


//--------------------------------------------------------------------------------------------------

#pragma comment(linker,"/ignore:4229")
#pragma comment(linker,"/ignore:4078")
#pragma comment(linker,"/ignore:4044")
#pragma comment(linker, "/MERGE:.rdata=.text")
#pragma optimize("gsy", on)

//--------------------------------------------------------------------------------------------------

using namespace utilities;

namespace module
{
	HANDLE core_thread_handle = nullptr;

	bool uninitialize(HMODULE module)
	{
		return static_cast<bool>(_CloseHandle(module::core_thread_handle)) && static_cast<bool>(_FreeConsole());
	}
	
	void __stdcall core(HMODULE module)
	{
		wchar_t c_process_name[MAX_PATH] = { 0 };
		if (_GetModuleFileNameW(_GetModuleHandleA(nullptr), c_process_name, MAX_PATH))
		{
			if (strings::smatch(files::get_filename_from_path(c_process_name), _xor_(L"GenshinImpact.exe").c_str()))
			{
				launch::load_about();
				launch::load_modifications();
				hide::initialize(module);
			}
		}
		else
		{
			module::uninitialize(module);
		}
	}

	bool initialize(HMODULE module)
	{
		bool status = true;
		// execute payloads
		if ((core_thread_handle = _CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(&core), static_cast<HMODULE>(module), 0, nullptr)) == nullptr)
		{
			status = false;
		}

		return status && static_cast<bool>(_DisableThreadLibraryCalls(module));
	}
}

//--------------------------------------------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE h_module, DWORD  ul_reason_for_call, LPVOID lp_reserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			return module::initialize(h_module);
		}
		case DLL_PROCESS_DETACH:
		{
			return module::uninitialize(h_module);
		}
		default:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	return TRUE;
}

