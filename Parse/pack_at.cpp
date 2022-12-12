#pragma once

#include"ErrorCode.cpp"

namespace pse
{
	template<typename type, typename A, typename... B>
	auto pack_at(int count, auto size, A a, B... b) -> type
	{
		if (count == size)
		{
			return a;
		}
		else
		{
			count += 1;
			//return pack_at<type, B...>(size, b...);
			return pack_at<type, A, B...>(count, size, a, b...);
		}
	}

	template<typename type, typename A>
	auto pack_at(int count, auto size, A a) -> type
	{
		if (count == size)
		{
			return a;
		}

		else
		{
			return type{}; // Basically a null value.
		}
	}
} // namespace pse