#pragma once

namespace pse
{
	template<int A, int B>
	constexpr auto Most()
	{
		return A < B;
	}
}