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

	template<auto T, auto... Ts>
	struct pack_size_
	{
		static constexpr auto value = 1 + pack_size_<Ts...>::value;
	};

	template<auto T>
	struct pack_size_<T>
	{
		static constexpr auto value = 1;
	};

}