// So this file is for metaprogramming algorithms!

#pragma once

#include"Tuple.hpp"

namespace pse
{
	// A generic get
	template<auto I, typename T, typename... Ts>
	consteval auto get(TupleT<T, Ts...>& tuple) noexcept(I <= sizeof...(Ts))
	{
		if constexpr(I == 0)
		{
			return tuple.first;
		}
		else
		{
			return get<I - 1, Ts...>(TupleT.second);
			// delegates
		}
	}

	template<auto I, typename T>
	consteval auto get(TupleT<T>& tuple) noexcept(I <= 1)
	{
		if constexpr (I == 0)
		{
			return tuple.first;
		}
		else
		{
			throw;
		}
	}

	template<typename T, typename... Ts>
	struct TupleIndex
	{
		T& t = nullptr;
		TupleIndex<Ts...>& ts = nullptr;

		template<typename Function>
		auto apply(Function& func)
		{
			func(t);
			ts.apply(func);
			// so then this call delegates to the rest of the elements.
		}

		TupleIndex(TupleT<T, Ts...>& t)
		{
			t = t.first;
			ts = t.second;
		}
	};

	template<typename T, typename... Ts>
	constexpr auto make_TupleIndex(T t, Ts... ts)
	{
		return TupleIndex<T, Ts...>(t, ts...);
	}

	// for_each on tuples.
	template<typename Function, typename T, typename... Ts>
	consteval auto for_each(Function& f, TupleT<T, Ts...>& tuple) noexcept
	{
		//integer_sequence int_seq = make_index_sequence < 0, tuple>
		TupleIndex<T, Ts...> indexes{ make_TupleIndex<T, Ts...>(tuple) };
		indexes.apply(f);
		// this applies it to all of the elements, we don't even need IndexSequence.
	}

	template<typename... Ts, typename... Hs>
	auto concat(TupleT<Ts...>& t1, TupleT<Hs...>& t2)
	{
		return concat<Ts..., Hs...>(t1, t2);
	}
}