#pragma once

namespace pse
{
	template<typename T, int Size>
	struct Array
	{

		auto operator[](int size)
		{
			return m_arr[size];
		}

		auto operator+=(T j)
		{
			T temp[Size];
			for (int i = 0; i < Size; i++)
			{
				temp[i] = m_arr[Size];
			}
			delete[] m_arr;

			m_arr = new T[Size * 2];
			int i = 0;
			for (i; i < Size; i++)
			{
				m_arr[i] = temp[i];
			}

			m_arr[i] = j;

			return *this;
		}

		template<int size>
		auto operator+=(T (&arr)[size])
		{
			T temp[Size];
			for (int i = 0; i < Size; i++)
			{
				temp[i] = m_arr[Size];
			}
			delete[] m_arr;

			m_arr = new T[Size * 2];
			int i = 0;
			for (i; i < Size; i++)
			{
				m_arr[i] = temp[i];
			}

			for (int i = 0; i < Size + size; i++)
			{
				m_arr[i] = arr[i];
			}
			return *this;
		}

	private:
		T m_arr[Size];
	};
} // namespace pse