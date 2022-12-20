#pragma once

#include"ArrCpy.cpp"

namespace pse
{
	// FIXME: Give better implemenatation of String

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

		StringList() {/*Needs implementing.*/ }

		auto print()
		{
			for(int i = 0; i < size; i++)
			{
				
				// std::cout << c_arr[i];
				if (i != size - 1)
				{
					//std::cout << "";
				}
			}
		}

		int size = 1;
		char c_arr[1]{};
	};
} // namespace pse
