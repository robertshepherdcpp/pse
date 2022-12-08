#pragma once

namespace pse
{
	template<auto T, auto... Ts>
	struct TupleCTAD
	{
		decltype(T) value;
		TupleCTAD<Ts...> rest;

		template<auto X>
		auto get()
		{
			if constexpr(X == 0)
			{
				return value;
			}
			else
			{
				return rest.get<X - 1>();
			}
		}
	};

	template<auto T>
	struct TupleCTAD<T>
	{
		decltype(T) value;

		template<auto X>
		auto get()
		{
			if constexpr (X == 0)
			{
				return value;
			}
		}
	};
} // namespace pse