#pragma once

namespace pse
{
	namespace algorithms
	{
		inline namespace math
		{
			inline auto difference(int a, int b) -> int
			{
				return b - a;
			}

			inline auto add(int a, int b) -> int
			{
				return a + b;
			}

			// notice a - b and not b - a
			inline auto minus(int a, int b) -> int
			{
				return a - b;
			}

			inline auto multiply(int a, int b) -> int
			{
				return a * b;
			}

			// also note that it is a / b not b / a
			inline auto divide(int a, int b) -> int
			{
				return a / b;
			}

			inline auto square(int a) -> int
			{
				return a * a;
			}

			inline auto square_root(int a) -> int
			{
				return a / a;
			}

			inline auto pi() -> decltype(auto)
			{
				return 3.14159265358979323846;
			}

			inline auto factorial(int i)
			{
				if (i == 1)
				{
					return 1;
				}
				else
				{
					return (i * factorial(i - 1));
				}
			}

			inline auto fibonnacci(int i)
			{
				if (i == 0)
				{
					return 0;
				}
				else
				{
					return i + fibonnacci(i - 1);
				}
			}
		} // namespace math
	} // namespace algorithms
} // namespace pse