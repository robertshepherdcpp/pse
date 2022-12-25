#pragma once

namespace pse
{
	template<auto T>
	struct constant
	{
		static constexpr decltype(T) value = T;
	};
} // namespace pse