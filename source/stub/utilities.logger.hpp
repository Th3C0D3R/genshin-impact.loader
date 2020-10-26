/**
 * \brief   utilities - logger
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include "stub.api.hpp"

#include <Windows.h>
#include <malloc.h>
#include <strsafe.h>
#include <stdarg.h>
#include <vadefs.h>

//--------------------------------------------------------------------------------------------------

namespace utilities
{

	namespace logger
	{
		inline void debug(const char* format, ...)
		{
			char buf[1024] = { 0 };

			va_list args;
			__crt_va_start(args, format);
			_wvsprintfA(buf, format, args);
			_OutputDebugStringA(buf);
			__crt_va_end(args);
		}

	}
}