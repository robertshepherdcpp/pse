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

	};

	template<typename T>
	struct TupleLike<T>
	{
		T first;
	};
} // namespace pse