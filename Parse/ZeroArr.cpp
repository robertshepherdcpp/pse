#pragma once

namespace pse
{
	template<typename T, int Size>
	auto ZeroArr(T (&arr)[Size]) -> void
	{
		for (int i = 0; i < Size; i++)
		{
			arr[i] = 0;
		}
	}
	// void return type
} // namespace pse