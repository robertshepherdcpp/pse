#pragma once

namespace pse
{
	// A way to find the size of a parameter pack at compile time.
	template<typename T, typename... Ts>
	struct pack_size
	{
		static constexpr auto value = 1 + pack_size<Ts...>::value;
	};

	template<typename T>
	struct pack_size<T>
	{
		static constexpr auto value = 1;
	};
}