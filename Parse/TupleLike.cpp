namespace pse
{

	template<typename T, typename... Ts>
	struct TupleLike;

	template<typename T>
	struct TupleLike<T>;

	template<typename T, typename B, typename A, typename...Bs> // Bs need to be here because of greedy matching
	auto make_TupleLike(T t, TupleLike<A, Bs...> tuple, B b)
	{
		//return Tuple<T, A, Bs..., B>(t, tuple/*Find a way of getting data out of the tuple*/, b)
		return make_TupleLike(t, tuple.first, b);
		/*
		* FIXME: This does not do what it is supposed to do:
		* It is supposed to use all elements of the TupleLike type
		* 
		* Needs to pass in both tuple.first and tuple.seconds.
		*/
	}

	template<typename T, typename S, typename B, typename A>
	auto make_TupleLike(T t, S s, TupleLike<A> tuple, B b)
	{
		return TupleLike<T, S, A, B>();
	}

	template<auto T, auto C, auto A, auto... B>
	auto make_tuplelike()
	{
		/*
		* Was thinking of just passing in A and B...
		* 
		* But could pass them in as NTTP
		*/

		return TupleLike<decltype(T), decltype(A), decltype(B)..., decltype(C)>(T, A, B..., C);
	}

	struct NoType {};

	// we need to make s varaidic because of the increasing template parameters, could just do
	// it like in c++98 where you have to manually do it.
	template<typename T, typename S, typename B, typename A, typename... Bs>
	auto make_TupleLike(T t, S s, TupleLike<A, Bs...> tuple, B b)
	{
		make_TupleLike(t, s, tuple.first, tuple.seconds, b);
		// need to make this now variadic becuae the amount of .first's and seconds' goes up linearly.
	}

	/*
	* auto make_TupleLike(T t, TupleLike)
	*/

	namespace global_elements_tupleLike
	{
		auto count = 0;
	}

	template<typename T, typename... Ts>
	auto GetParameterPackIndex(TupleLike<T, Ts...> tuple, auto index)
	{
		if(global_elements_tupleLike::count == index)
		{
			return tuple.first;
		}
		else 
		{
			// we have to increment global_elements_tupleLike like this:
			global_elements_tupleLike::count += 1;
			return GetParameterPackIndex(TupleLike.seconds, index);
		}
	}

	template<typename T>
	auto GetParameterPackIndex(TupleLike<T> tuple, auto index
	{
		return tuple.first; // no exception hanling currently, if wrong input from the user it is the user's fault.
	}
    
	template<typename T, typename... Ts>
	auto get_tuple_elements(TupleLike<T, Ts...>& tuple)
	{
		if(tuple.index == 0)
		{
		return T;
		}
		else
		{
			/*
			Index is to show that becuase we are going to use this function like this:
			get_tuple_elements(tuple)...
			We are going to need to know how deep we need to go in the TupleLike object. For instance:

			tuple.first;
			tuple.seconds;
			tuple.seconds.first;
			tuple.seconds.seconds.first;

			Extra so we need a count to track to get all of the elements in the TupleLike object.
			*/
			tuple.index++;
			return GetParameterPackIndex(tuple, tuple.index);
		}
	}

	template<typename T, typename... Ts>
	auto GetType(T t, Ts... ts)
	{
		return t + ts...;
	}

	template<typename T, typename B, typename A>
	auto make_TupleLike(T t, TupleLike<A> tuple, B b)
	{
		return Tuple<T, A, B>(t, tuple, b);
	}


    /*
	Have hit a conumdrum with make_TupleLike becuase i can't define it like this:

	template<typename T, typename B, typename... Ts, typename... Tstwo>
	auto make_TupleLike(T t, Ts... ts, TupleLike<Tstwo...> tuple, B b)
	{
		return make_TupleLike(t, ts..., tuple.first, tuple.seconds, b);
	}

	and then have the base case as:

	template<typename T, typename... Ts, typename Ttwo>
	auto make_TupleLike(T t, Ts... ts, TupleLike<Ttwo> tuple, B b)
	{
		return TupleLike<T, Ts..., decltype(tuple.first), B>(t, ts..., tuple.first, b);
	}

	but is impossible becuase i am not allowed two parameter packs together because
	which one they would go in would be ambiguous.

	so i am not sure what to do.

	I could have one parameter pack. Yes that is what i will do. No i cannot do that because i have got to have that tuple variadic args.
	*/

	template<typename T, typename... Ts>
	struct TupleLike
	{
		template<typename B>
		auto push_back(B b) // need a different type because it is a tuple structure
		{
			auto curr_tuple = make_TupleLike(first, b, seconds);
			return curr_tuple; // curr_tuple is of type Tuple<decltype(first), decltype(b), decltype(seconds.get_data())
			                   // still to be implemented seconds of type TupleLike .get_data()
		}

		T first;
		TupleLike<Ts...> seconds;
		int index = 0;

	};

	template<typename T>
	struct TupleLike<T>
	{
		T first;
		int index = 0;
	};
} // namespace pse