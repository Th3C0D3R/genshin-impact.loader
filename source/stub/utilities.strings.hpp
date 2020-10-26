/**
 * \brief   utilities - strings
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include <cassert>
#include <string>


//--------------------------------------------------------------------------------------------------

namespace utilities
{
	namespace strings
	{
		inline char to_lower(char ch)
		{
			if (ch > 96 && ch < 123) 
			{
				ch -= 32;
			}
			return ch;
		}
		
		inline wchar_t to_lower(wchar_t ch)
		{
			if (ch > 0x40 && ch < 0x5B) 
			{
				return ch + 0x20;
			}
			return ch;
		}

		inline int isalnum(char num)
		{
			if (num > 64 && num < 91 || num > 96 && num <123 || num > 47 && num < 58) 
			{
				return 1;

			}
			return 0;
		}
		
		template<typename char_type>
		inline int length(char_type *str)
		{
			int length;

			for (length = 0; str[length] != '\0'; length++) {}
			return length;
		}

		// sensitive match
		template<typename char_type>
		inline bool smatch(char_type *str1, char_type* str2)
		{
			if (str1 == nullptr || str2 == nullptr || length(str1) != length(str2))
			{
				return false;
			}

			for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
			{
				if (str1[i] != str2[i])
				{
					return false;
				}
			}
			return true;
		}

		
		// insensitive match
		template<typename char_type>
		inline bool imatch(char_type *str1, char_type* str2)
		{
			if (str1 == nullptr || str2 == nullptr || length(str1) != length(str2))
			{
				return false;
			}

			for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
			{
				if (to_lower(str1[i]) != to_lower(str2[i]))
				{
					return false;
				}
			}
			return true;
		}

		template<typename char_type>
		inline bool contains(char_type* haystack, char_type* needle)
		{
			if (haystack == nullptr || needle == nullptr) 
			{
				return false;
			}

			for (int i = 0; haystack[i] != '\0'; i++) 
			{
				if (to_lower(haystack[i]) == to_lower(needle[0]))
				{
					bool found = true;
					for (int j = 1; needle[j] != '\0'; j++) 
					{
						if (to_lower(haystack[i + j]) != to_lower(needle[j]))
						{
							found = false;
						}
					}
					if (found) 
					{
						return true;
					}
				}
			}
			return false;
		}

		inline wchar_t* cstr2wstr(char* str)
		{
			int len = length(str);

			if (str == nullptr) 
			{
				return nullptr;
			}

			wchar_t *wstr_t = (wchar_t *)malloc(sizeof(wchar_t) * len + 2);

			for (int i = 0; i < len; i++)
			{
				wstr_t[i] = str[i];
			}
			wstr_t[len] = '\0';
			return wstr_t;
		}
		
		template<typename char_type>
		inline char_type *strchr(char_type *s, char_type c)
		{
			const char_type *p;
			for (p = s + length(s); p >= s && *p != c; p--);
			return p >= s ? (char_type *)p : 0;
		}


	}
}
