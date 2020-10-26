/**
 * \brief   utilities - files
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include "utilities.xor.hpp"
#include "utilities.strings.hpp"

#include <Windows.h>
#include <direct.h>

#include<iostream>
#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------

namespace utilities
{
	namespace files
	{
		template<typename char_type>
		inline char_type* get_filename_from_path(char_type* path)
		{
			if (path == nullptr)
			{
				return nullptr;
			}

			char_type * p_file_name = path;
			for (char_type * p_cur = path; *p_cur != ('\0'); p_cur++)
			{
				if (*p_cur == ('/') || *p_cur == ('\\'))
				{
					p_file_name = p_cur + 1;
				}
			}

			return p_file_name;
		}
		
		template<typename char_type>
		inline char_type* get_extension(const char_type *string)
		{
			char_type *ext = strings::strchr<char_type>((char_type*)string, ('.'));

			if (ext == nullptr)
			{
				return (char_type*)string + strings::length(string);
			}

			for (char_type *iter = ext + 1; *iter != ('\0'); iter++)
			{
				if (!strings::isalnum((unsigned char)*iter))
				{
					return (char_type*)string + strings::length(string);
				}
			}

			return ext;
		}
	}
}
