#pragma once

namespace pse
{
	namespace detail
	{
		enum month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
		enum day {Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun};
		enum class comparison { greater = 1, same, less };
	}
	struct Time
	{
		Time(int year, detail::month& m, detail::day& d)
		{
			m_year = year;
			m_month = m;
			m_day = d;
		}

		auto date()
		{
			// This needs implementing as i was going to return a type
			// that is just like a string, but i would need to implement
			// to_string and from_string and things like that.
		}

		auto comparison(Time& t) -> detail::comparison
		{
			/*
			* It will work the further back in time the less the date is.
			*/
			if (m_year == t.m_year)
			{
				if (m_month == t.m_month)
				{
					if (m_day == t.m_day)
					{
						return detail::comparison::same;
					}
					else if(m_day > t.m_day)
					{
						return detail::comparison::less;
					}
					else
					{
						return detail::comparison::greater;
					}
				} // if(m_month == t.m_month)
				else if (m_month < t.m_month)
				{
					return detail::comparison::greater;
				}
				else if(m_month > t.m_month)
				{
					return detail::comparison::less;
				}
			}
			else if (m_year < t.m_year)
			{
				return detail::comparison::greater;
			}
			else if (m_year > t.m_year)
			{
				return detail::comparison::less;
			}
		}

		int m_year{};
		int m_month{};
		int m_day{};
	};
} // namespace pse