#pragma once

#include"Vector.cpp" // pse::Vector

namespace pse
{
	// to show what orientation the Bitmap is.
	struct Vertical {};
	struct Horizontal {};

	struct Bitmap
	{
		template<int down>
		Bitmap(Vertical& v, pse::Vector<int>& vec);

		template<int accross>
		Bitmap(Horizontal& h, pse::Vector<int>& vec);

		// auto get() -> decltype(auto) { return m_Bitmap; }
		// Error cannot return an array int[1][1]

		int m_size = 1;
		int m_length = 0;
		int m_width = 0;

		int m_Bitmap[1][1]{};
	};

	template<int down>
	Bitmap::Bitmap(Vertical& v, pse::Vector<int>& vec)
	{
		// Bitmap will look like this:
        // 1, 6, 11
		// 2, 7, 12
		// 3, 8, 13
		// 4, 9, 14
		// 5, 10
		// 
		// When given the following numbers
		//{pse::Vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}};

		// And passed the following arguements:
		// Vertical, 5, and the vector shown above.

		//////////////////////////////////////////////////////////////////////////////


		/*
		m_size = vec.size;
		const int z = m_size % down;
		const int x = (m_size + z) / down; // finding how many vertical columns.
		int m = 0;
		if (accross != 1 and x != 1)
		{
			m_Bitmap = new int[down][x]{};
		}
		for (int i = 0; i < down && i < m_size; i++)
		{
			for (int j = 0; i < x && i < m_size; j++)
			{
				m++;
				m_Bitmap[j][i] = vec[m];
			}
		}
		*/

		m_size = vec.size();

		const int x = m_size % down;
		const int z = (m_size + x) / down;
		int m = 0;
		m_Bitmap = new int[z][down]{};

		for (int i = 0; i < down && i < m_size; i++)
		{
			for (int j = 0; i < x && i < m_size; j++)
			{
				m++;
				m_Bitmap[i][j] = vec[m];
			}
		}


	}

/* int arr[6][6]  

	* [0, 0], [1, 0], [2, 0], [3, 0], [4, 0], [5, 0]
	* 
	* [0, 1], [1, 1], [2, 1], [3, 1], [4, 1], [5, 1]
	* 
	* [0, 2], [1, 2], [2, 2], [3, 2], [4, 2], [5, 2]
	* 
	* [0, 3], [1, 3], [2, 3], [3, 3], [4, 3], [5, 3]
	* 
	* [0, 4], [1, 4], [2, 4], [3, 4], [4, 4], [5, 4]
	* 
	* [0, 5], [1, 5], [2, 5], [3, 5], [4, 5], [5, 5]
*/
	template<int accross>
	Bitmap::Bitmap(Horizontal& h, pse::Vector<int>& vec)
	{
		// Bitmap will look like this:
		// 1, 6, 11
		// 2, 7, 12
		// 3, 8, 13
		// 4, 9, 14
		// 5, 10
		// 
		// When given the following numbers
		//{pse::Vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}};

		// And passed the following arguements:
		// Vertical, 5, and the vector shown above.

		// Bitmap will look like this:
		// 1, 2, 3, 4, 5
		// 6, 7, 8, 9, 10,
		// 11, 12
		//
		// When given the following numbers:
		// {pse::Vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}};

		// And passsed the following arguements:
		// Horizontal{}, 5, and the vector shown above

		//////////////////////////////////////////////////////////////////////////////////

		m_size = vec.size;
		const int z = m_size % accross;
		const int x = (m_size + z) / accross; // finding how many vertical columns.
		int m = 0;
		if (accross != 1 and x != 1)
		{
			m_Bitmap = new int[accross][x]{};
		}
		for (int i = 0; i < accross && i < m_size; i++)
		{
			for (int j = 0; i < x && i < m_size; j++)
			{
				m++;
				m_Bitmap[i][j] = vec[m];
			}
		}
	}
}