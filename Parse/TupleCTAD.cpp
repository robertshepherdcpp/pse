#pragma once

namespace pse
{
	// this TupleCTAD use an idiom that makes it seem like a TupleCTAD has a smaller size than it really has.
	// for instance if I do this:
	/*
	* TupleCTAD<42, 'c', 0.0, true> tuple{};
	* auto x = tuple.get<0>();
	* x();
	* tuple.remove_first();
	* auto y = tuple.get<0>();
	* y();
	* 
	* y() and x() have different types even though we have called tuple.get<0>() twice on the same object.
	*/
	template<auto T, auto... Ts>
	struct TupleCTAD
	{
		decltype(T) value;
		TupleCTAD<Ts...> rest;
		bool first_removed = false;

		auto remove_first()
		{
			if (first_removed == false)
			{
				first_removed = true;
			}
			else
			{
				rest.remove_first();
			}
		}

		template<auto X>
		auto get()
		{
			if constexpr(X == 0 && first_removed == false)
			{
				return value;
			}
			else if constexpr(X == 0 && first_removed == true)
			{
				return rest.get<X>();
			}
			else
			{
				return rest.get<X - 1>();
			}
		}

		template<auto X>
		auto get_type() -> decltype(T)
		{
			if constexpr (X == 0 && first_removed == false)
			{
				return value;
			}
			else if constexpr (X == 0 && first_removed == true)
			{
				return rest.get<X>();
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
		bool first_removed = false;

		auto remove_first()
		{
			first_removed = true;
		}

		template<auto X>
		auto get()
		{
			if constexpr (X == 0 && first_removed == false)
			{
				return value;
			}
			else
			{
				// do nothing as no elements left in the tuple
			}
		}

		template<auto X>
		auto get_type() -> decltype(T)
		{
			if constexpr (X == 0 && first_removed == false)
			{
				return value;
			}
			else
			{
				// do nothing as no elements left in the tuple
			}
		}
	};
} // namespace pse