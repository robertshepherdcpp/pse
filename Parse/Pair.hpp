#pragma once

namespace pse
{
	template<typename A, typename B>
	struct Pair
	{
		A first;
		B second;

		auto operator[](int i)
		{
			if (i == 0)
			{
				return first;
			}
			else
			{
				return second;
			}
		}
	};
} // namespace pse