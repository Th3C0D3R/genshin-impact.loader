/**
 * \brief   utilities - api
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include <string>
#include <Windows.h>

//--------------------------------------------------------------------------------------------------

namespace utilities
{
	namespace api
	{
		FARPROC address(char* dll_name, char* proc_name);
	}
}