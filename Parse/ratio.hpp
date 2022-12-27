#pragma once

namespace pse
{
	template<auto T, auto B>
	struct Ratio
	{
		constexpr decltype(T) numerator = T;
		constexpr decltype(B) denominator = B;
	};

	template<auto A, auto B, auto C, auto D>
	auto operator==(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A == C) && (B == D));
	}

	template<auto A, auto B, auto C, auto D>
	auto operator<(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) < (C / D);
	}

	template<auto A, auto B, auto C, auto D>
	auto operator>(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) > (C / D);
	}

	template<auto A, auto B, auto C, auto D>
	auto operator<=(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) <= (C / D);
	}

	template<auto A, auto B, auto C, auto D>
	auto operator>=(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) >= (C / D);
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_add(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return Ratio<A + C, B + D>{};
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_minus(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return Ratio<A - C, B - D>{};
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_multiply(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return Ratio<A * C, B * D>{};
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_divide(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return Ratio<A / C, B / D>{};
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_equal(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A == C) && (B == D));
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_less(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) < (C / D));
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_less_or_equal(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) <= (C / D));
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_greater(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) > (C / D));
	}

	template<auto A, auto B, auto C, auto D>
	constexpr auto ratio_greater_or_equal(Ratio<A, B>& a, Ratio<C, D>& b)
	{
		return ((A / B) >= (C / D));
	}

} // namespace pse