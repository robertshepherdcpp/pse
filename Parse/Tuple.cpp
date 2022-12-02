#pragma once

namespace pse
{
	template<auto T, auto... Ts>
	struct Tuple
	{
		decltype(T) value = T;
		Tuple<Ts...> values{};
	};

	template<auto T>
	struct Tuple<T>
	{
		decltype(T) value = T;
	};

	// prefer Tuple over TupleCTAD because with Tuple you can just do:
	// Tuple<5, 8, "Hello", '.'> v;
} // namespace pse