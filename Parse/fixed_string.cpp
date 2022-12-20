#pragma once

namespace pse
{
	template<auto T>
	struct fixed_string
	{
		char m_arr[T + 1];
		fixed_string(char(&arr)[T])
		{
			//copy_n();

			for (int i = 0; i < T; i++)
			{
				m_arr[i] = arr[i];
			}
		}
	};
} // namespace pse