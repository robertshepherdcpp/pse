#pragma once

#include"ArrCpy.cpp"

namespace pse
{
	// FIXME: Give better implemenatation of String
	template<auto T>
	struct String
	{
		// template<auto T>
		String(char (&arr)[T]) // so array does not decay
		{
			ArrCpy(m_str, arr);
		}

		String(const char[8]) // just to get rid of compiler error
		{
		}

		auto operator[](int index)
		{
			return m_str[index];
		}

		auto operator==(String<T>& s) -> bool
		{
			for (int i = 0; i < T; i++)
			{
				if (s[i] != m_str[i])
				{
					return false;
				}
			}
			return true;
		}

		char m_str[T]; // array of chars of size T
	};

	
} // namespace pse