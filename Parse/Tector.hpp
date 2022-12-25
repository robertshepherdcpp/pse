#pragma once

namespace pse
{
	template<typename T, typename... Ts>
	struct Init
	{
		T first;
		Init<Ts...> second;

		Init(T t, Ts... ts);
		auto get(int i)->T;
		auto operator[](int i)->T;
		auto operator=(Init<T, Ts...>& i);
	};

	template<typename T, typename... Ts>
	Init<T, Ts...>::Init(T t, Ts... ts)
	{
		first = t;
		auto x = Init<Ts...>(ts...);
		second = x;
	}

	template<typename T, typename... Ts>
	auto Init<T, Ts...>::operator=(Init<T, Ts...>& t)
	{
		first = t.first;
		second = t.second;
	}

	template<typename T, typename... Ts>
	auto Init<T, Ts...>::get(int i) -> T
	{
		if (i == 0)
		{
			return first;
		}
		else
		{
			return second.get(i - 1);
		}
	}

	template<typename T, typename... Ts>
	auto Init<T, Ts...>::operator[](int i) -> T
	{
		return get(i);
	}

	template<typename T>
	struct Init<T>
	{
		T first;
		// no second.

		auto get(int i) -> T 
		{ 
			return first; 
		}

		auto operator[](int i) -> T 
		{ 
			return first;
		}

		auto operator=(T t)
		{
			first = t;
		}

		auto operator=(Init<T>& i)
		{
			first = i.first;
		}
	};

} // namespace pse