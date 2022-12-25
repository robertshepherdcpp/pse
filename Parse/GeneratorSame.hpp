#pragma once

#include"TupleCTAD.hpp" // pse::TupleCTAD

namespace pse
{
	// this is for a Generator of the same types so that we don't have problems with
	// varying return types like we have for a pse::Generator of different types.
	template<auto T, auto... Ts>
	struct GeneratorSame
	{
		pse::TupleCTAD<T, Ts...> diffs{};

		auto operator()()
		{
			auto x = diffs.get<0>();
			diffs.remove_first();
			return x;
		}
	};

	template<auto T>
	struct GeneratorSame<T>
	{
		pse::TupleCTAD<T> diffs{};

		auto operator()()
		{
			auto x = diffs.get<0>();
			diffs.remove_first();
			return x;
		}
	};
} // namespace pse