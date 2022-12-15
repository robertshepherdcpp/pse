#pragma once

#include"Most.cpp"
#include"ZeroArr.cpp"

namespace pse
{
	template<auto T1, auto T2> // size of arr
	auto ArrCpy(char (&arr)[T1], char(&arr2)[T2]) -> void // passed by reference
	{
		constexpr int size = Most(T1, T2);
		if (size > T1)
		{
			delete[] arr;
			arr = new char[size];
		}
		// char str_m[size];
		// copying into arr not a new var
		//ZeroArr(arr);
		decltype(arr[0]) arr_copy[T1];
		for (int i = 0; i < T1; i++)
		{
			arr_copy[i] = arr[i];
		}
		for (int i = 0; i < Most(T1, T2); i++)
		{
			arr[i] = arr2[i];
		}
		for (int i = 0; i < T1; i++)
		{
			arr2 = arr_copy[i];
		}
	}
}