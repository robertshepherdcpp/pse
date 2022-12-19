#pragma once

#include"ArrCpy.cpp"

namespace pse
{
	// FIXME: Give better implemenatation of String
    //template<auto T>
	template<auto X>
	struct String
	{
		// template<auto T>
		template<auto T>
		String(char (&arr)[T]) // so array does not decay
		{
			if (T != size)
			{
				m_str = new char[T];
			}
			size = T;
			// ArrCpy(m_str, arr);
			for (int i = 0; i < T; i++)
			{
				m_str[i] = arr[i];
			}
		}

		String(const char[8]) // just to get rid of compiler error
		{
		}

		auto operator[](int index)
		{
			return m_str[index];
		}

		auto operator==(String& s) -> bool
		{
			for (int i = 0; i < s.size; i++)
			{
				if (s[i] != m_str[i])
				{
					return false;
				}
			}
			return true;
		}

		int size = 0;
		char m_str[1]; // array of chars of size T
	};

	struct String_
	{
		// template<auto T>
		template<auto T>
		explicit String_(char(&arr)[T]) // so array does not decay
		{
			if (T != size)
			{
				m_str = new char[T];
			}
			size = T;
			// ArrCpy(m_str, arr);
			for (int i = 0; i < T; i++)
			{
				m_str[i] = arr[i];
			}
		}

		auto operator[](int index)
		{
			return m_str[index];
		}

		auto operator==(String_& s) -> bool
		{
			for (int i = 0; i < s.size; i++)
			{
				if (s[i] != m_str[i])
				{
					return false;
				}
			}
			return true;
		}

		String_() {}

		int size = 0;
		char m_str[1]{}; // array of chars of size T
	};
} // namespace pse