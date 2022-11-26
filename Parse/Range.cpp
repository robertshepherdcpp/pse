#pragma once

#include"Initializer_List.cpp" // pse::Initializer_List
#include"Algo.cpp" // pse::algorithms

namespace pse
{
	inline namespace Ranges
	{
		template<typename T>
		struct Range
		{
			Range(Initializer_List<T>& init)
			{
				auto Size = init.size();
				arr = new T[Size];
				for (int i = 0; i < init.size(); i++)
				{
					arr[i] = init[i];
				}
			}

			inline auto Take(int prefix, int postfix)
			{
				auto diff = algorithms::difference(postfix - prefix);
				T temp[size]{};
				for (int i = 0; i < size; i++)
				{
					temp[i] = arr[i];
				}
				size = diff;
				arr = new T[diff];
				for (int i = prefix; i < postfix; i++)
				{
					arr[i - prefix] = temp[i];
				}
			}

			decltype(auto) print()
			{
				return arr;
			}

			inline static int size = 1;
			T arr[1];
		};
	} // namespace Ranges
} // namespace pse