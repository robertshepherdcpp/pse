#pragma once

#include"Initializer_List.cpp"

namespace pse
{
	// arr <- list
	template<typename T, typename B, int Size>
	auto CopyInitializerToArr(Initializer_List<T>& list, B(&arr)[Size])
	{
		for (int _ = 0; _ < list.size(); _++)
		{
			arr[_] = list[_];
		}
	}

	// arr1 <- arr2
	template<typename T, int Size>
	auto CopyArr(T (&arr)[Size], T (&arr2)[Size])
	{
		for (int i = 0; i < Size; i++)
		{
			arr[i] = arr2[i];
		}
	}


}; // namespace pse