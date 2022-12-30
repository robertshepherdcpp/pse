namespace pse
{
	template<auto A, auto B, auto C>
	struct Unit
	{
		double m_value{};

		double get_value() { return m_value; }
		Unit(double value) { m_value = value; }
	};

	using Scalar = Unit<0, 0, 0 >;
	using Meters = Unit<1, 0, 0 >;
	using SquareMeters = Unit<2, 0, 0 >;
	using Kilograms = Unit<0, 1, 0 >;
	using Seconds = Unit<0, 0, 1 >;
	using Mps = Unit<1, 0, -1>;

	template<auto D1, auto M1, auto T1, auto D2, auto M2, auto T2>
	auto operator/(Unit<D1, M1, T1>& first, Unit<D2, M2, T2>& second) -> decltype(auto)
	{
		constexpr int D = D1 - D2;
		constexpr int M = M1 - M2;
		constexpr int T = T1 - T2;

		return Unit<D, M, T>(first.get_value() / second.get_value());
	}

	template<auto D1, auto M1, auto T1, auto D2, auto M2, auto T2>
	auto operator*(Unit<D1, M1, T1>& first, Unit<D2, M2, T2>& second) -> decltype(auto)
	{
		constexpr int D = D1 - D2;
		constexpr int M = M1 - M2;
		constexpr int T = T1 - T2;

		return Unit<D, M, T>(first.get_value() * second.get_value());
	}

	template<auto D1, auto M1, auto T1, auto D2, auto M2, auto T2>
	auto operator%(Unit<D1, M1, T1>& first, Unit<D2, M2, T2>& second) -> decltype(auto)
	{
		constexpr int D = D1 - D2;
		constexpr int M = M1 - M2;
		constexpr int T = T1 - T2;

		return Unit<D, M, T>(first.get_value() % second.get_value());
	}

	template<auto D1, auto M1, auto T1, auto D2, auto M2, auto T2>
	auto operator+(Unit<D1, M1, T1>& first, Unit<D2, M2, T2>& second) -> decltype(auto)
	{
		constexpr int D = D1 - D2;
		constexpr int M = M1 - M2;
		constexpr int T = T1 - T2;

		return Unit<D, M, T>(first.get_value() + second.get_value());
	}

	template<auto D1, auto M1, auto T1, auto D2, auto M2, auto T2>
	auto operator-(Unit<D1, M1, T1>& first, Unit<D2, M2, T2>& second) -> decltype(auto)
	{
		constexpr int D = D1 - D2;
		constexpr int M = M1 - M2;
		constexpr int T = T1 - T2;

		return Unit<D, M, T>(first.get_value() - second.get_value());
	}
} // namespace pse