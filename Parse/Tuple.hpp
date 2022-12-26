#pragma once

#include"ErrorCode.hpp"

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
		else
		{
			throw ErrorCode{ 026 };
		}

		// else do nothing.
	}

	template<typename T, typename... Ts>
	struct TupleT
	{
		T first{};
		TupleT<Ts...> second{};
	};

	template<typename T>
	struct TupleT<T>
	{
		T first{};
	};

	// warning this function does not assign elements.
	template<typename... As, typename... Bs>
	auto tuple_cat(TupleT<As...>& tuple_a, TupleT<Bs...>& tuple_b)
	{
		return TupleT<As..., Bs...>{};
	}
} // namespace pse