#pragma once

namespace pse
{
	template<auto A, auto B>
	constexpr auto Most()
	{
		return A < B;
	}

	template<typename A, typename B>
	constexpr auto Most(A a, B b)
	{
		return a < b;
	}
}