#pragma once

#include"Traits.cpp" // AddPointer

namespace pse
{
	template<typename T>
	struct Iterator
	{
		auto operator++();
		auto operator++(int x);

		auto operator--();
		auto operator--(int x);

		decltype(auto) get() { return it; }
		decltype(auto) get_val() { return *it; }

		auto operator*() { return get_val(); }
		auto operator->() { return get_val(); }

		auto operator-=(int i) { it = it - i; }
		auto operator+=(int i) { it = it + i; return it; }

		Iterator(T* t) { it = t; }
		Iterator(T t) { /*it = Traits::Add_Pointer<T>::value{};*/ }

		using type = T*;
		T* it;
	};

	template<typename T>
	auto Iterator<T>::operator++()
	{
		it += 1;
		return it;
	}

	template<typename T>
	auto Iterator<T>::operator++(int x)
	{
		it += 1;
		return it;
	}

	template<typename T>
	auto Iterator<T>::operator--()
	{
		it -= 1;
		return it;
	}

	template<typename T>
	auto Iterator<T>::operator--(int x)
	{
		it -= 1;
		return it;
	}
} // namespace pse