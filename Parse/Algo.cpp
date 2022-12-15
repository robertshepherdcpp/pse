#pragma once

#include"Iterator.cpp" // pse::Iterator<T>
#include"Traits.cpp" // pse::IsSame<>

namespace pse
{
	namespace algorithms
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

			template<typename T> // template needed for the Iterator variable i.
			auto OnAll(Iterator<T> j, auto& Lambda)
			{
				for (int i = 0; i < j.size; j++)
				{
					i++;
					Lambda(j.get_val());
				}
			}

			template<typename T>
			auto Invoke(T t) -> decltype(t())
			{
				return t();
			}

			template<typename T>
			auto Reverse(Iterator<T>& j)
			{
				// just reverse the elements. Could just use the functionality of the iterator like operator+ etc.
				for (int i = 0; i < j.size(); i++)
				{
					auto x = j.get_ref();
					x = j.get_ref() - i;
					j.get_ref() - i = j.get_ref();
				}
			}

			template<typename A, typename B>
			auto swap(Iterator<A>& ai, Iterator<B>& bi)
			{
				auto x = ai.get_ref(); // have a reference so we can use the lower level part of Iterator.
				x = bi.get_ref();
				auto j = bi.get_ref();
				ai.get_ref() = j; // swap using reference variables
			}

			template<typename T, typename Callable>
			auto Sort(Iterator<T>& t, Callable c)
			{
				// implementation still is needed.
				if (c(t.get_val(), t.get_increment()))
				{
				  swap(t, t++);
				}
			}

			// uses a reference for the value.
			template<typename T>
			auto Sort(Iterator<T>& t) -> void
			{
				//if (t.get_val() > t.get_increment())
				//{
				//	t.get_ref() = t.get_increment().get_ref()); // implementatation still needed.
				//}
			}

			auto find(auto& a, auto& ToFind) -> int
			{
				for (int i = 0; i < a.size(); i++)
				{
					if (a[i] == ToFind)
					{
						return i;
					}
				}
				return 0;
			}

			auto find_if(auto& a, auto& Callable) -> int
			{
				for (int i = 0; i < a; i++)
				{
					if (Callable(a[i])) // requires Callable to return a bool
					{
						return i;
					}
				}
				return 0;
			}

			auto reverse(auto& a)
			{
				int x = 0;
				for (int i = a.size(); i > 0; i++, x++)
				{
					auto temp = a[i];
					a[i] = a[x];
					a[x] = a[i];
				}
			}

			template<typename T>
			concept has_type_member = requires(T t)
			{
				t.type != nullptr;
			};

			// just like std::accumulate
			template<typename T>
			auto gather(T& to_gather)
			{
				T sum{};
				for (int i = 0; i < to_gather.size(); i++)
				{
					sum += to_gather;
				}

				return sum; // passed by reference so doesn't really need to do it.
			}

			// just like std::accumulate
			// this specialisation needs fixing because it does the same thing as the non 
			// specialised function.
			template<typename T>
			requires(has_type_member<T>)
			auto gather(T& to_gather)
			{
				//to_gather.type sum{};
				T sum{};
				for (int i = 0; i < to_gather.size(); i++)
				{
					sum += to_gather[i];
				}
				return sum;
			}

			struct add {};
			struct minus {};
			struct multiply {};
			struct divide {};

			// this function is a bit like std::exclusive_scan or std::inclusive scan.
			template<typename T>
			auto apply(T& t, auto& operator_apply, auto& operator_two)
			{
				T sum{};
				for (int i = 0; i < t.size(); i++)
				{
					if (Traits::Is_Same<add, decltype(operator_apply)>::value == true)
					{
						if (Traits::Is_Same < add, decltype(operator_two)>::value == true)
						{
							sum += T[i] + T[i + 1];
						}
						else if (Traits::Is_Same < minus, decltype(operator_two)>::value == true)
						{
							sum += T[i] - T[i + 1];
						}
						else if (Traits::Is_Same < multiply, decltype(operator_two)>::value == true)
						{
							sum += T[i] * T[i + 1];
						}
						else if (Traits::Is_Same < divide, decltype(operator_two)>::value == true)
						{
							sum += T[i] / T[i + 1];
						}
					} // if(add == decltype(operator_apply))
					else if (Traits::Is_Same<minus, decltype(operator_apply)>::value == true)
					{
						if (Traits::Is_Same < add, decltype(operator_two)>::value == true)
						{
							sum -= T[i] + T[i + 1];
						}
						else if (Traits::Is_Same < minus, decltype(operator_two)>::value == true)
						{
							sum -= T[i] - T[i + 1];
						}
						else if (Traits::Is_Same < multiply, decltype(operator_two)>::value == true)
						{
							sum -= T[i] * T[i + 1];
						}
						else if (Traits::Is_Same < divide, decltype(operator_two)>::value == true)
						{
							sum -= T[i] / T[i + 1];
						}
					} // else if(minus == decltype(operator_apply))
					else if (Traits::Is_Same<multiply, decltype(operator_apply)>::value == true)
					{
						if (Traits::Is_Same < add, decltype(operator_two)>::value == true)
						{
							sum *= T[i] + T[i + 1];
						}
						else if (Traits::Is_Same < minus, decltype(operator_two)>::value == true)
						{
							sum *= T[i] - T[i + 1];
						}
						else if (Traits::Is_Same < multiply, decltype(operator_two)>::value == true)
						{
							sum *= T[i] * T[i + 1];
						}
						else if (Traits::Is_Same < divide, decltype(operator_two)>::value == true)
						{
							sum *= T[i] / T[i + 1];
						}
					} // else if(multiply == decltype(operator_apply))
					else if (Traits::Is_Same<minus, decltype(operator_apply)>::value == true)
					{
						if (Traits::Is_Same < add, decltype(operator_two)>::value == true)
						{
							sum /= T[i] + T[i + 1];
						}
						else if (Traits::Is_Same < minus, decltype(operator_two)>::value == true)
						{
							sum /= T[i] - T[i + 1];
						}
						else if (Traits::Is_Same < multiply, decltype(operator_two)>::value == true)
						{
							sum /= T[i] * T[i + 1];
						}
						else if (Traits::Is_Same < divide, decltype(operator_two)>::value == true)
						{
							sum /= T[i] / T[i + 1];
						}
					} // else if(minus == decltype(operator_apply))
				}
			}

			// Lambdas that can pass to functions like pse::OnAll();

				inline auto Square = [](auto i)         {return i * i; };
				inline auto Plus   = [](auto i, auto j) {return i + j; };
				inline auto Times  = [](auto i, auto j) {return i * j; };
				inline auto Minus  = [](auto i, auto j) {return i - j; };
			
	} // namespace algorithms
} // namespace pse