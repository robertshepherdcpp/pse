#pragma once

namespace pse
{
	static int var_size = 0;


	// if constexpr allows multiple return types in an expression.
	// because the compiler doesnt bother looking at the other return statements
	// because it is happening at compile time.
	template<int size>
	constexpr auto get(auto& Obj)
	{
		if constexpr(var_size == size)
		{
			return Obj.value;
		}
		if constexpr(var_size != size)
		{
			var_size += 1;
			return get<size>(Obj.values);
		}
	}
} // namespace pse