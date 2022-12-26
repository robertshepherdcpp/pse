#pragma once

namespace pse
{
	template<auto StartNum, typename T, typename... Ts>
	struct integer_sequence
	{
		static constexpr auto index = StartNum;
		T first;
		integer_sequence<StartNum + 1, Ts...> second;

		const decltype(StartNum) indices[sizeof...(Ts) + 1]{ index, second.indices };


		// so we do operator[] and return the index/type depending on the aruement.

	};

	template<auto StartNum, typename T>
	struct integer_sequence<StartNum, T>
	{
		static constexpr auto index = StartNum;
		T first;

		const decltype(StartNum) indices[1]{ index };
	};

	template<typename T, typename... Ts>
	constexpr auto make_integer_sequence()
	{
		return integer_sequence<0, T, Ts...>{};
	}

	template<typename T>
	constexpr auto make_integer_sequence()
	{
		return integer_sequence<0, T>{};
	}
}