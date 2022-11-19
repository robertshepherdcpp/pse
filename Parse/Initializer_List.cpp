#pragma once

//#include"ParameterPackSize.cpp" // Implement
#include"Traits.cpp"

namespace pse
{
	static int Parameter_Pack_Size_ = 0;

	template<typename T, typename... Ts>
	auto ParameterPackSize(T t, Ts... ts)
	{
		Parameter_Pack_Size_ += 1;
		ParameterPackSize(ts...);
	}

	template<typename T>
	auto ParameterPackSize(T t)
		requires(Traits::Is_Type<T>::value)
	{
		Parameter_Pack_Size_ += 1;
		int _s = Parameter_Pack_Size_;
		Parameter_Pack_Size_ = 0; // reset for next invokation of this function
		return _s;
	}

	template<typename T>
	struct Initializer_List
	{
		// auto InitHelper(T t, T... ts)
		// Dont need now

		auto operator[](int i)
		{
			return m_arr[i];
		}

		template<int size>
		auto get()
		{
			return m_arr[size];
		}

		auto size()
		{
			return (sizeof(m_arr) / sizeof(T)) == size ? size : sizeof(m_arr) / sizeof(T);
		}

		Initializer_List(T t)
		{
			delete[] m_arr;
			m_arr = new T[1];
			Size = 1;
			m_arr[0] = t;
		}

		template<typename... Ts>
		Initializer_List(T t, Ts... ts)
		{
			auto size = 1 + ParameterPackSize(ts...);
			delete[] m_arr;
			m_arr = new T[size];
			m_arr[0] = t;
			auto Initializer_List_ = Initializer_List<T>(ts...);
			*this += Initializer_List_;
			// InitHelper(ts..., m_arr, 1);

			/*Not sure if can do this because the parameter pack is greedy and would
			Get all of the other args like: m_arr and 1.
			- Will need to make an initialzer list out of parameter pack and then use and 
			  implemented += operator to add the initialzer list to the current array:
			  m_arr.*/
		}
		int Size = 1;
		T m_arr[1];
	};
} // namespace pse