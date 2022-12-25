#pragma once

namespace pse
{
	template<typename... Ts>
	struct overload : Ts...
	{
		using Ts::operator()...;
	};

	// For more see nicola josuttis C++17 book.
	template<typename... Ts>
	overload(Ts...)->overload<Ts...>;
} // namespace pse