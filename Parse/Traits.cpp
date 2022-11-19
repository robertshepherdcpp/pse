#pragma once

namespace pse
{
	namespace Traits
	{
		template<typename T>
		struct Is_Type
		{
			static constexpr auto value = true;
		};

		template<typename A, typename B>
		struct Is_Same;

		template<typename T>
		struct Is_Same<T, T>;

		template<typename A, typename B>
		concept same_as = requires(A a, B b)
		{
			Is_Same<A, B>::value;
		};

		template<typename A, typename B>
		struct Is_Same
		{
			static constexpr auto value = false;
		};

		template<typename T>
		struct Is_Same<T, T>
		{
			static constexpr auto value = true;
		};
	} // namespace Traits
} // namespace pse