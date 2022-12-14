#pragma once

namespace pse
{
	template<auto T, auto... Ts>
	struct Tuple
	{
		decltype(T) value = T;
		Tuple<Ts...> values{};

		template<auto Index>
		auto get();
		int index = 0;
	};

	template<auto T, auto... Ts>
	template<auto Index>
	auto Tuple<T, Ts...>::get()
	{
		if constexpr (Index == index)
		{
			index = 0;
			return value;
		}
		else
		{
			index++;
			return values.get<Index - 1>();
		}
	}

	template<auto T>
	struct Tuple<T>
	{
		decltype(T) value = T;
		template<auto Index>
		auto get();

		int index = 0;
	};

	template<auto T>
	template<auto Index>
	auto Tuple<T>::get()
	{
		if constexpr (Index == index)
		{
			index = 0;
			return value;
		}

		// else do nothing.
	}

	// prefer Tuple over TupleCTAD because with Tuple you can just do:
	// Tuple<5, 8, "Hello", '.'> v;
} // namespace pse