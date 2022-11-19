#pragma once

#include"ArrCpy.cpp"
#include<iostream> // std::cout

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

	struct StringList
	{
		template<int Size>
		StringList(char(&arr)[Size])
		{
				char temp[size];
				if (Size > size)
				{
				for (int i = 0; i < size; i++)
				{
					temp[i] = c_arr[i];
				}

				c_arr = new char[Size];
				size = Size;
			}
			for (int i = 0; i < size && i < size; i++)
			{
				c_arr[i] = arr[i];
			}
		}

		auto print()
		{
			for(int i = 0; i < size; i++)
			{
				
				std::cout << c_arr[i];
				if (i != size - 1)
				{
					//std::cout << "";
				}
			}
		}

		int size = 1;
		char c_arr[1];
	};
} // namespace pse