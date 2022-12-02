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
		decltype(auto) get_ref() { return it; } // does the same thing as get() does just a better name.

		auto operator*() { return get_val(); }
		auto operator->() { return get_val(); }

		auto begin() { return it; }
		// End is just a sentinel value.
		auto end() { return Iterator{}; }

		auto operator-=(int i) { it = it - i; }
		auto operator+=(int i) { it = it + i; return it; }

		auto get_increment() { it += 1; return *this; } // basically just *this.operator++().get();
		auto get_decrement() { it = -1; return *this; } // basically just *this.operator--().get();

		auto get_plusEquals(auto i) { return it += i; } // just so we can do it in one function
		auto get_plusMinus(auto i) { return it -= i; }  // just so we can do it in one function.

		Iterator(T* t) { it = t; }
		Iterator(T t) { /*it = Traits::Add_Pointer<T>::value{};*/ }
		Iterator(T* t, int size_) { it = t; size = size_; }

		// could/should delete this.
		Iterator() {/*Do nothing but if try to do member functions, it is underined behavior*/ }

		auto operator==(Iterator<T>& iter)
		{
			return iter.it == it && *iter.it == *it;
		}

		auto operator!=(Iterator<T>& iter)
		{
			return iter.it != it && *iter.it == *it;
		}

		int size = 0;

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