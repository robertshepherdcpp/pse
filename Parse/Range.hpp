#pragma once

#include"Initializer_List.hpp" // pse::Initializer_List
#include"Algo.hpp" // pse::algorithms
#include"constant.hpp" // pse::constant
#include"Traits.hpp" // pse::Traits::Add_Const<T>::value

namespace pse
{
	//inline namespace Ranges
	//{
	template<typename T>
	struct Range
	{
		// this sturcture is just like a pse::Initializer_List just for 
		template<typename T, typename... Ts>
		struct DataRange
		{
			DataRange(T t, Ts... ts)
			{
				First = t;
				Seconds = DataRange<Ts...>{ ts... };
			}

			DataRange()
			{
			}

			auto Value()
			{
				return value;
			}

			auto begin() { return First; }
			auto end() { return get(size()); }

			auto size()
			{
				return Value() + Seconds.Value();
			}

			auto operator[](int i)
			{
				return get(i);
			}

			auto get(int i) -> T
			{
				if (i > size())
				{
					return int{}; // we are returning the default value of the first template parameter pack
					// as it is just like an initializer list
				}
				if (i == 0)
				{
					return First;
				}
				else
				{
					return Seconds.get(i - 1);
				}
			}

			static constexpr int value = 1;

			T First{};
			DataRange<Ts...> Seconds{};
		};

		template<typename T>
		struct DataRange<T>
		{
			DataRange(T t)
			{
				First = t;
			}

			auto Value()
			{
				return value;
			}

			static constexpr int value = 1;

			T First{};
		};

		//Range(Initializer_List<T>& init)
		//{
		//	auto Size = init.size();
		//	arr = new T[Size];
		//	for (int i = 0; i < init.size(); i++)
		//	{
		//		arr[i] = init[i];
		//	}
		//}

		Range()
		{
			// doesn't need an implementation
		}

		template<auto T>
		struct constant
		{
			static constexpr decltype(T) value = T;
		};

		template<typename A, typename... Bs>
		Range(A a, Bs... bs)
		{
			/*
			* We now need some way of storing this parameter pack, we could use an initializer list,
			* or we can just make our own in our local scope.
			*/

			//auto Data = DataRange<A, Bs...>{ a, bs... };

			//constexpr auto value = constant<size>::value; // shouldn't really do.

			//T temp[value + 1]{};
			//for (int i = 0; i < size; i++)
			//{
			//	temp[i] = arr[i];
			//}
			//size = Data.size();
			//constexpr auto data_size = constant<Data.size()>::value;
			//delete[] arr;
			//arr = new T[data_size]{};
			//for (int i = 0; i < Data.size(); i++)
			//{
			//	arr[i] = Data[i];
			//}
		}

		inline auto Take(int prefix, int postfix)
		{
			//constexpr auto diff = algorithms::difference(postfix, prefix);
			constexpr auto diff = postfix - prefix;
			T temp[size]{};
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			size = diff;
			arr = new T[diff]{};
			for (int i = prefix; i < postfix; i++)
			{
				arr[i - prefix] = temp[i];
			}
		}

		// this function does not use `std::cout` trying to refrain from using the `std` namespace.
		decltype(auto) print()
		{
			return arr;
		}

		inline static int size = 1;
		T arr[1]{};
	};
	//} // namespace Ranges
} // namespace pse