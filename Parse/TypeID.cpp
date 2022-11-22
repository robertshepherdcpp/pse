#include"String.cpp" // string

namespace pse
{
	// FIXME: Use string implemenatation without having to pass in size of const char*
	template<typename T>
	auto parseType() //-> StringList
	{
		if constexpr(T() == 0) // 0 == int
		{
			return ("int");
		}
		if constexpr(T() == 0.0) // 0.0 == double
		{
			return ("double");
		}
		if constexpr(T() == ' ') // '' == char
		{
			return ("char");
		}
		if constexpr(T() == false)
		{
			return ("bool");
		}
		if constexpr(T() == String<2>(" "))
	        {
			return String<12>("const char*");
		}
	}

	template<typename T>
	auto parse()
	{
		return parseType<T>();
	}
} // namespace pse
