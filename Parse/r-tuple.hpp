#pragma once

namespace pse
{
	template<typename T, typename... Ts>
	struct r_tuple
	{
		T first;
		r_tuple<Ts...> second;
	};

	template<typename T>
	struct r_tuple
	{
		T first;
	};

	template<auto I, typename T, typename... Ts>
	auto get(r_tuple<T, Ts...>& t)
	{
		if constexpr (I == 0)
		{
			return tup.first;
		}
		else constexpr (I != 0)
		{
			return get<I - 1>(tup);
		}
	}

	template<auto I, typename T>
	auto get(r_tuple<T>& t)
	{
		if constexpr (I == 0)
		{
			return tup.first;
		}
		else constexpr (I != 0)
		{
			return get<I - 1>(tup);
		}
	}

	template< int I, class T >
	struct tuple_element;

	// recursive case
	template< int I, class Head, class... Tail >
	struct tuple_element<I, r_tuple<Head, Tail...>>
		: std::tuple_element<I - 1, std::tuple<Tail...>> { };

	// base case
	template< class Head, class... Tail >
	struct tuple_element<0, r_tuple<Head, Tail...>> {
		using type = Head;
	};

	template<int I, typename... Ts>
	using tuple_element_t = tuple_element<I, Ts...>::type;
} // namespace pse