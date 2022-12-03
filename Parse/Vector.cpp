#pragma once

#include"ZeroArr.cpp"
#include"Copy.cpp"
#include"Initializer_List.cpp"

/*implement:
    - Copy.cpp
	¬ CopyInitializerToArr()
	¬ CopyArr()

	- Initializer_List.cpp
	*/

namespace pse
{
	template<typename T>
	struct Vector
	{
		Vector()
		{
			ZeroArr(m_arr); // initialize array.
		}

		Vector(T t)
		{
			delete m_arr;
			m_arr = new T[1];
			m_arr = t;
			size = 1;
		}

		Vector(Initializer_List<T>& list)
		{
			CopyInitializerToArr(list, m_arr);
		}

		auto operator=(Vector<T>& v)
		{
			CopyArr(v.m_arr, m_arr);
		}

		auto operator[](int z)
		{
			return m_arr[z];
		}

		auto operator=(T t)
		{
			delete[] m_arr;
			m_arr = new T[1];
			m_arr[0] = t;
			size = 1;
		}

		auto operator=(Initializer_List<T>& list)
		{
			CopyInitializerToArr(list, m_arr);
		}

		auto push_back(T t)
		{
			T temp[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = m_arr[i];
			}
			delete[] m_arr;
			m_arr = new T[size * 2];

			int j = 0;

			for (j; j < size; j++)
			{
				m_arr[j] = temp[j];
			}
			m_arr[j + 1] = t;

		}
		int size{};
		T m_arr[1];
	};
} // namespace pse