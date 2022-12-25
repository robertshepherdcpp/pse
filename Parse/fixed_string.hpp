#pragma once

#include"copy_n.hpp" // pse::copy_n

namespace pse
{
	template<auto N>
	struct fixed_string
	{
		char m_arr[N + 1] = {};
		constexpr fixed_string(const char(&arr)[N + 1]) { copy_n(arr, N + 1, m_arr); }

		// need <compare> for the spaceship operator.
		//auto operator<=>(const fixed_string&) const = default;
	};
} // namespace pse