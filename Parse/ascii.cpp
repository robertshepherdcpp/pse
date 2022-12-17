// inspiration taken from foonathon/lexy

#pragma once

namespace pse
{
	namespace ascii
	{
	template<char T>
	struct ToBinary
	{
		static constexpr int value = static_cast<int>(T);
	};

	template<int T>
	struct ToCharacter
	{
		static constexpr char value = static_cast<char>(T);
	};

	auto ToString(int i)
	{
		// FIXME: Implememt.
	}

	auto ToInt(const char*)
	{
		// FIXME: Implement.
	}

	template<auto T>
	auto is_space()
	{
		if constexpr (T == ' ')
		{
			return true;
		}
		return false;
	};

	template<auto T>
	auto is_punctuation()
	{
		if constexpr (T == '!' || T == '"' || T == '\n' || T == '.' || T == ',' || T == '?' || T == '/' || T == '~')
		{
			return true;
		}
		return false;
	}

	template<char A, char B>
	struct is
	{
		static constexpr bool value = (A == B);
	};

	template<char T>
	struct is_punc
	{
		static constexpr bool value = (T == '!' || T == '"' || T == '\n' || T == '.' || T == ',' || T == '?' || T == '/' || T == '~');
	};

	template<char T>
	struct is_alphabetical
	{
		static constexpr auto value = ((static_cast<int>(T) > 96) && (static_cast<int>(T) < 123));
	};

	template<char T>
	struct is_character // has to be, we were passed in a char.
	{
		static constexpr bool value = true;
	};

	static constexpr auto space = ' '; // punc
	static constexpr auto dot = '.'; // punc
	static constexpr auto comma = ',';
	static constexpr auto backslash = '\\';
	static constexpr auto forwardslash = '/';
	static constexpr auto at = '@';
	static constexpr auto percent = '%';
	static constexpr auto pound = '£';
	static constexpr auto explanationmark= '!';
	static constexpr auto dollar= '$';
	static constexpr auto up = '^';
	// static constexpr auto and = '&';
	static constexpr auto star = '*';
	static constexpr auto openingbracket= '(';
	static constexpr auto closingbracket= ')';
	static constexpr auto plus = '+';
	static constexpr auto minus = '-';
	static constexpr auto opensquarebracket= '[';
	static constexpr auto closesquarebracket = ']';
	static constexpr auto opencurlybrace= '{';
	static constexpr auto closecurlybrace= '}';
	static constexpr auto hash= '#';
	static constexpr auto hyphen= '~';
	static constexpr auto greater = '>';
	static constexpr auto less= '<';
	static constexpr auto questionmark = '?';
	static constexpr auto a = 'a'; // alphabetical
	static constexpr auto b = 'b'; // alphabetical
	static constexpr auto c = 'c'; // alphabetical
	static constexpr auto d = 'd'; // alphabetical
	static constexpr auto e = 'e'; // alphabetical
	static constexpr auto f = 'f'; // alphabetical
	static constexpr auto g = 'g'; // alphabetical
	static constexpr auto h = 'h'; // alphabetical
	static constexpr auto i = 'i'; // alphabetical
	static constexpr auto j = 'j'; // alphabetical
	static constexpr auto k = 'k'; // alphabetical
	static constexpr auto l = 'l'; // alphabetical
	static constexpr auto m = 'm'; // alphabetical
	static constexpr auto n = 'n'; // alphabetical
	static constexpr auto o = 'o'; // alphabetical
	static constexpr auto p = 'p'; // alphabetical
	static constexpr auto q = 'q'; // alphabetical
	static constexpr auto r = 'r'; // alphabetical
	static constexpr auto s = 's'; // alphabetical
	static constexpr auto t = 't'; // alphabetical
	static constexpr auto u = 'u'; // alphabetical
	static constexpr auto v = 'v'; // alphabetical
	static constexpr auto w = 'w'; // alphabetical
	static constexpr auto x = 'x'; // alphabetical
	static constexpr auto y = 'y'; // alphabetical
	static constexpr auto z = 'z'; // alphabetical

	template<char T>
	struct is_symbol
	{
		static constexpr bool value = (T == percent || T == at); // more needs implementing here.
	};
	} // namespace binary

} // namespace pse