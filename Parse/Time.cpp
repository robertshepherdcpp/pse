#pragma once

#include"StringList.cpp"

namespace pse
{
	inline namespace detail
	{
		enum month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
		enum day {Mon = 1, Tue, Wed, Thu, Fri, Sat, Sun};
		enum class comparison { greater = 1, same, less };

		static constexpr auto MinutesPerHour = 60; 
		int hours_to_mins(int i) { return i * MinutesPerHour; }

		static constexpr auto SecondsPerMinute = 60; 
		int minutes_to_seconds(int i) { return i * SecondsPerMinute; }
		
		static constexpr auto SecondsPerHour = SecondsPerMinute * MinutesPerHour; 
		int hours_to_seconds(int i) { return i * SecondsPerHour; }
		
		static constexpr auto HoursPerDay = 24; 
		int days_to_hours(int i) { return i * HoursPerDay; }
		
		static constexpr auto WeeksPerYear = 52; 
		int years_to_weeks(int i) { return i * WeeksPerYear; }
		
		static constexpr auto DaysPerYear = 365; 
		int years_to_days(int i) { return i * DaysPerYear; }
		
		static constexpr auto MonthsPerYear = 12; 
		int years_to_months(int i) { return i * MonthsPerYear; }

		static constexpr auto HoursPerYear = DaysPerYear * HoursPerDay; 
		int years_to_hours(int i) { return i * HoursPerYear; }
		
		static constexpr auto MinutesPerYear = HoursPerYear * MinutesPerHour; 
		int years_to_minutes(int i) { return i * MinutesPerYear; }
		
		static constexpr auto SecondsPerYear = HoursPerYear * SecondsPerHour; 
		int years_to_seconds(int i) { return i * SecondsPerYear; }
		
		static constexpr auto YearsPerDecade = 10; 
		int decades_to_years(int i) { return i * YearsPerDecade; }
		
		static constexpr auto DecadesPerCentury = 10; 
		int century_to_decades(int i) { return i * DecadesPerCentury; }
		
		static constexpr auto YearsPerCentury = YearsPerDecade * DecadesPerCentury; 
		int century_to_years(int i) { return i * YearsPerCentury; }
		// could be all the data above into the Secod, Minute, Hour classes.
		struct Second { int count; };
		struct Minute { int count; };
		struct Hour { int count; };
		struct Day { int count; };
		struct Week { int count; };
		struct Month { int count; };
		struct Year { int count; };

		auto operator""_second(long double s)
		{
			return Second{ static_cast<int>(s) };
		}

		auto operator""_minute(long double m)
		{
			return Minute{ static_cast<int>(m) };
		}

		auto operator""_hour(long double h)
		{
			return Hour{ static_cast<int>(h) };
		}

		auto operator""_day(long double d)
		{
			return Day{ static_cast<int>(d) };
		}

		auto operator""_week(long double w)
		{
			return Week{ static_cast<int>(w) };
		}

		auto operator""_month(long double m)
		{
			return Month{ static_cast<int>(m) };
		}

		auto operator""_year(long double y)
		{
			return Year{ static_cast<int>(y) };
		}

		// Think that i will stop at year because i could just keep on going.
	}
	struct Time
	{
		Time(int year, detail::month& m, detail::day& d)
		{
			m_year = year;
			m_month = m;
			m_day = d;
		}

		Time(StringList& a)
		{
			// with this we will split the string into it's appropriate data members.
		}

		//auto operator/()
		//{
			// Needs implementing, but first we need a better pse::StringList.
		//}

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

		int m_year{0};
		int m_month{0};
		int m_day{0};
	};
} // namespace pse