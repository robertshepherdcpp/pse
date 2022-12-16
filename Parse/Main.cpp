#pragma once

#include"String.cpp" // String
#include"Begin.cpp" // Begin
#include"UselessObj.cpp"
#include"Tuple.cpp"
// #include<string> was here but taken away because i dont think is needed.
#include"Vector.cpp" // FIXME: Make a better implementation of Vector
#include"Traits.cpp"
#include"Get.cpp" // pse::get
#include"Array.cpp"
#include"ImplicitEquals.cpp"
#include"Variant.cpp"
#include"TypeID.cpp"
#include"Visit.cpp" // pse::Visit
#include"overload.cpp" // pse::overload
#include"TupleLike.cpp" // pse::TupleLike
#include"Iterator.cpp" // pse::Iterator
#include"Range.cpp" // pse::Range
#include"Bitmap.cpp" // pse::Bitmap
#include"Generator.cpp" // pse::Generator
#include"Type.cpp" // pse::Type
#include"Vec.cpp" // pse::Vec

#include<cassert>

// #include<iostream> // std::cout

// only using the standard library for std::cout
// Currently getting an error because of Bitfender doing checks whilst
// trying to compile the code.
// Link: https://learn.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk1104?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(LNK1104)%26rd%3Dtrue&view=msvc-170

template<typename T_>
auto make_T(auto T, auto... Ts)
{
	return T_{ T, Ts... };
}

// c++20 concepts
template<typename T>
concept HasPlusOperator = requires(T t)
{
	t += t;
};

template<typename T, int i>
pse::Array<T, i> v{};

// uses concepts to show that HasPlus operator can be added because that is how this function 
// Works.
// Notice the _|_
//            \ /
//             .
template<HasPlusOperator Obj, auto c, auto... cs>
constexpr auto CharToStringNTTP()

{
	auto object_val = make_T<Obj, c, cs...>;
	return object_val + CharToStringNTTP(cs...);
}

template<typename T>
struct s
{
	auto push_back(T t)
	{
		// do nothing just a pointless type
	}
};

struct EnumerationType
{
	EnumerationType(int string)
	{
		Enums.push_back(string);
	}

	s<int> Enums;
};

// ^
// |  FIXME. Need better implementation of this.

constexpr auto HasSameConstexpr(auto T, auto Str)
{
	return true; // return true for now, even though done no parsing
}

template<typename T, auto Str>
struct SomePartStrHas
{
	constexpr auto value()
	{
		return HasSameConstexpr(T{}.name(), Str);
	}
};

template<typename T, typename Str>
struct NameOf
{
	static constexpr auto value = Str::name;
};

template<auto Str, auto Obj>
struct ParseNonMember
{
	auto parse() { /*...*/ }
};

//template<auto Str, auto Obj> // NTTP syntax obj.Member func
//struct ParseNonMember < pse::String<8>("begin()"), tse::UselessObj{} >
//{
//	auto parse()
//	{
//		if constexpr (SomePartStrHas<NameOf<decltype(Obj)>, Str>::value)
//		{
//			return tse::Begin(Obj);
//		}
//	}
//};

inline namespace G_lobal
{
	static int TupleSize = 0;
}

/*
auto FindTupleSize(auto& Tuple_)
{
	TupleSize++;
	return FindTupleSize(Tuple_.values);
}

template<auto T>
auto FindTupleSize(pse::Tuple<T>& t)
{
	TupleSize++;
	Tuple_s = TupleSize;
	TupleSize = 0;
	return Tuple_s;
}

template<typename T>
auto FindTupleSize(T t)
{
	return TupleSize;
}
*/

template<auto T, decltype(T)... B>
struct Homogeneous
{
};

template<auto T>
struct constant
{
	decltype(T) value = T;
};

struct Widget {
	int d;
	constexpr int array_size() const { return d * (d + 1) / 2; }
};

// From Daisy Hollmans cute tricks
// 
// constexpr auto bad(Widget w) {
//   return std::array<int, w.array_size()>{};  // doesn't compile
// }

template <auto> struct ConstexprParam {};
template <auto v> inline auto ConstexprArg = ConstexprParam<v>{};

template <Widget w>
constexpr auto good(ConstexprParam< w >) {
	return pse::Array<int, w.array_size()>{};  // works fine!!!
}

constexpr Widget foo{ 42 };
// Doesn't compile:
// auto my_array = bad(foo);
auto my_array = good(ConstexprArg<foo>);

template<typename T>
class Base
{
	T value{};

public:
	Base()
	{
		// ...
	}

	Base(T v) : value{ v }
	{
		// ...
	}
};

template<typename... Types>
struct Multi : private Base<Types>
{
	using Base<Types>::Base...;
};

using m = Multi<int, char, bool, double>;

template<typename T>
struct type
{
	using value = T;
};

/*--------------------------------------------------------------------------
-----------------------------Testing----------------------------------------
----------------------------------------------------------------------------
*/


template<typename T, typename... Ts>
struct Parameter
{

};

template<typename T>
struct Parameter<T>
{

};

// we get an error as we cannot have a parameter pack that is not at the end of a template
// parameter list as one would always be empty.

//template<typename T, typename... Ts, typename... Ts2>
template<typename T, typename B>
struct Parameter<T, B>//<T, Ts..., Ts2...>
{

};

/*--------------------------------------------------------------------------
-----------------------------Testing----------------------------------------
----------------------------------------------------------------------------
*/



template<typename T>
struct Class : T
{
	using T::T;
};

template<typename T>
constexpr auto c() -> Class<T>
{
	return Class<T>();
}

template<typename T>
auto class_v = Class<T>();

auto bassert(bool b, auto& s)
{
	if (!b)
	{
		//std::cout << s << " failed.\n";
	}
	else
	{
		//std::cout << s << " passed.\n";
	}
}

template <typename... Ts>
struct any_type : Ts... {};

/*
 * Find someway of using this like a pse::TupleLike:
 */

namespace when {
	struct first {};
	struct second {};
	struct third {};
}  // namespace when

int maintwo() {
	auto Lambda1 = [](when::first& f) { /*std::cout << "First.\n";*/ };
	auto Lambda2 = [](when::second& s) { /*std::cout << "Second.\n";*/ };
	auto Lambda3 = [](when::third& t) { /*std::cout << "Third.\n"; */ };

	any_type any_t{ Lambda1, Lambda2, Lambda3 };

	// we inherit the call operator of the lamda so should work just by calling
	// any_t

	// any_t(when::first{}); error ambiguos function call operator() even though i am passing when::first 
	//                       which there is only one of but, compiler still thinks that it is ambiguous.

	return 42;
}

//template<typename A, typename B, typename C, typename D>
struct set_arg
{
	int a;
	int b;
	int c;
    int d;

	set_arg(int _a, int _b, int _c, int _d)
	{
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}

	auto operator[](int i)
	{
		if (i == 0)
		{
			return a;
		}
		else if (i == 1)
		{
			return b;
		}
		else if (i == 2)
		{
			return c;
		}
		else if (i == 3)
		{
			return d;
		}
	}
};

int main()
{
	auto c_int = constant<42>{};
	//std::cout << c_int.value;
	//std::cout << "\n";
	// m p = 'c';
	pse::Tuple<42, 'c', true, 3.14> v{};
	// Dont need to initialize becuase everything is already initialized

	//pse::Visit
	(pse::overload{ [](pse::String<10>& s) {/*std::cout << "String.\n";*/ },
	[](int i) {/*std::cout << "Int.\n";*/ }},
		pse::Choices::ReturnUnWanted{}, 42);
	// do not know why this compiles. But it does.

// auto x = pse::get<0>(v);

	// std::cout << v.values.values.value;

	// std::cout << "\n" << x << "\n";
	// could do a chain like this.

	// auto x = v<int, 20>;
	// Or need to implement a better get function

	pse::ImplicitEquals(52, 52.3);

	//pse::Variant<c<int>(), c<char>(), c<bool>(), c<double>()> x{};
	// pse::Variant<class_v<int>> x{};

	auto x = pse::parse<int>();

	decltype(auto) string_ = "Hello What is Your Name?\n";
	// pse::StringList string{"Hello What is Your Name?\n"};
	//string.print();
	//constexpr bool b = (x == pse::String<12>("int"));
	// assert(x == pse::String<12>("int"), pse::String<28>("x == pse::String<12>(\"int\")"));

	//std::cout << "\nA float's default value is: " << float{} << " -- !.\n";

	// don't need to do it this style but can do: tupletwo{5, 3.0, 3.004, 'c', true};
	pse::TupleLike<int, double, float, char, bool> tupletwo{ 5, {3.0, {3.0004,{'c', {true}}}} };
	tupletwo.print(true);
	// tupletwo.push_back(42);

	pse::Range<int> r{ 1,2,3,4,1,2,3 }; // 1, 2, 3, 4, 1, 2, 3 ends up to be an something like an initializer list.
	// r.Take(2, 5);

	int arr[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	pse::Iterator iterator{ arr }; // assigns the first value of the array: arr.
	iterator++;

	iterator += 8;

	auto functionone = []() {return bool{}; };
	auto functiontwo = []() {return int{}; };

	//if (decltype(functionone){} == decltype(functiontwo){})
	//{
	//	std::cout << "functionone and function two both have the same types.\n";
	//}

	// if i use this code i get a link error.
	//int vector_a_arr[8]{ 5,3,4,5,9,3,6,2 };
	//pse::Vector<int> vector_a{ /*vector_a_arr*/ };

	// pse::Bitmap b(pse::down{}, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	// notice have to spell out the types that are being used.
	pse::TupleLike<int, int, int, int> tuple_like_{ 1, 2, 3, 4 };

	//pse::Generator < []() {return 42; }, []() {return 'c'; }, []() {return true; } > generator{};
	//pse::Generator<2, 6, 45, 2345, 345> generator{};
	//generator();
	//auto bjarne = generator();
	//auto stroustrup = generator();

	pse::Type t_a{ 42 };
	pse::Type t_b{ 56 };

	t_a.operator<=(t_b);

	// static_assert(t_a.i == 56);

	//pse::Vec<int> ikm{1, 2, 3, 4};
	// std::cout << ikm[2];
	// pse::Vec<int> ikm{ 1, 2, 3, 4 };

	//set_arg set{ 42, 3.1415, 'a', true };
	//pse::algorithms::apply(set, pse::algorithms::add{}, pse::algorithms::multiply{});

	pse::TupleCTAD<42, 36, 16, 5> decreasing{};
	// auto first_decreasing = decreasing.get<0>();
	// assert(first_decreasing == 42, "Has to passs.");

	return *iterator;

	// return "\nEnd\nOf\nProgram\n";
}