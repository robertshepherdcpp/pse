// So this file is for metaprogramming algorithms! 
// Basically just fun things to do with metaprogramming.

#pragma once

#include"Tuple.hpp"
#include"pack_at.hpp"

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

	// for_each on tuples
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
		return tuple_cat<Ts..., Hs...>(t1, t2);
	}

	template<typename T,typename... Ts>
	struct dummy_type
	{
		// just a holder for types.
	};

	template<typename T, typename... Ts>
	constexpr auto shorten_helper(dummy_type<Ts...>& d, T t)
	{
		// FIXME: Implement.
	}

	template<auto Current, auto Start, auto End, typename T, typename... Ts>
	requires(Current < Start && sizeof...(Ts) >= End)
	struct shorten
	{
		using shorten_ = shorten<Current + 1, Start, End, Ts...>::shorten_;
	};

	//template<auto Current, auto Start, auto End, typename T, typename... Ts>
	//requires(Current == Start && End <= sizeof...(Ts))
	//struct shorten
	//{
		//using shorten_ = shorten_helper(dummy_type<Ts...>, T{});
	//};

	template<auto T, typename Type, typename... Ts>
	auto shorten_pack(Type t, Ts... ts)
	{

	}

	template<typename T, typename... Ts>
	constexpr auto reverse(TupleT<T, Ts...>& t)
	{
		constexpr auto size = sizeof...(Ts) + 1;
		//constexpr auto last{t.get_ref<size - 1>()};
		constexpr auto first{ t.get<0>()};
		t.first = t.get<size - 1>();
		t.last = first;

		//reverse();
		// need to shorten parameter pack.
	}
}