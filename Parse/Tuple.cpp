namespace pse
{
	template<auto T, auto... Ts>
	struct Tuple
	{
		decltype(T) value = T;
		Tuple<Ts...> values{};
	};

	template<auto T>
	struct Tuple<T>
	{
		decltype(T) value = T;
	};

	// prefer Tuple over TupleCTAD because with Tuple you can just do:
	// Tuple<5, 8, "Hello", '.'> v;
	template<typename T, typename... Ts>
	struct TupleCTAD
	{
		T value;
		TupleCTAD<Ts...> rest;
	};

	template<typename T>
	struct TupleCTAD<T>
	{
		T value;
	};
} // namespace pse