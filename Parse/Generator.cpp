#pragma once

#include"TupleLike.cpp"
#include"TupleCTAD.cpp"
#include"pack_size.cpp"

// A more specialized Generator is located in GeneratorSame.cpp, this is for a generator
// That returns the same types

// don' t need it yet.

/*
* Robert Shepherd (c) Copywrite 2022
* Generator is just basically a programmable object:
*/

/*
* Generator.add_action([](){std::cout << "First Action"});
* Generator.add_actoin([](){std::cout << "Second Action"});
* 
* It is a bit like a coroutine in that it kindof suspends and resumes when called. An example
* of calling it is:
*
* Generator() // outputs "First Action"
* Generator() // outputs "Second Action"
* 
*/

/*
TupleLike is going to be exactly like a coroutine. But becuase with c++20 coroutines we have to use the standard library
like `std::coroutine_handle<>` and we are refraining from using the `std` library except from standard library. But still shouldn't really
use `std::cout`. Just a way of having a way of returning an object that is like another program in itself!
*/

/*
* Make TupleLike type.
* 
* What it does:
* 
* like a vector in that it can change size, but it can have many different types.
*/

namespace pse
{
	template<auto T, auto... Ts> // these are lambda types
	struct Generator
	{
		
		int count = 0;
		// TupleLike v{};
		
		TupleCTAD<T, Ts...> lambdas{};

		// Generator(T t, Ts... ts) { lambdas = TupleLike<T, Ts...>{ t, ts... }; count = lambdas.Size();}
		
		auto operator()() 
		{ 
		//	if (count != 0)
		//	{
		//		auto x = lambdas.Depth<count>();
		//		--count;
		//		return x();
		//	}
			auto x = lambdas.get<0>();
			lambdas.remove_first();
			return x;
		}
		//Genrerator(T t) {/*Dont do anything at the moment*/ }
		
	};
	
	template<auto T, auto... Ts>
	struct GeneratorCTAD
	{
		int sizetwo = 0;
		static constexpr int size = pack_size<T, Ts...>::value;
		static inline TupleCTAD<T, Ts...> lambdas{};
		
		auto operator()()
		{
			if(sizetwo < size)
			{
				auto x = lambdas.get<0>();
				return x();
			}
			sizetwo++;
		}
	};
};
