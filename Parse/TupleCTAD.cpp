#pragma once

namespace pse
{
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