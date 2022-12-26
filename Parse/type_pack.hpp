namespace pse
{
	template<typename T, T... types>
	struct type_pack
	{
		// just something that has lots of types, all of the same type, will be useful for
		// metaprogramming.
	};
}