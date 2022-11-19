#include"Most.cpp" // FIXME Needs implementing
#include"ZeroArr.cpp" // FIXME Needs implementing

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
		ZeroArr(arr);
		for (int i = 0; i < Most(T1, T2); i++)
		{
			arr[i] = arr2[i];
		}
	}
}