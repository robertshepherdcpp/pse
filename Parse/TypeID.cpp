#include"String.cpp" // string

namespace pse
{
	// FIXME: Use string implemenatation without having to pass in size of const char*
	template<typename T>
	auto parseType()
	{
		if constexpr(T() == 0) // 0 == int
		{
			return String<12>("int");
		}
		if constexpr(T() == 0.0) // 0.0 == double
		{
			return String<12>("double");
		}
		if constexpr(T() == ' ') // '' == char
		{
			return String<12>("char");
		}
		if constexpr(T() == false)
		{
			return String<12>("bool");
		}
		//if constexpr(T() == String(" "))
		//{
		//	return String<12>("const char*");
		//}
	}

	template<typename T>
	auto parse()
	{
		return parseType<T>();
	}
} // namespace pse