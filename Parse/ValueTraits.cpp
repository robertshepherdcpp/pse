#pragma once

#include"Traits.cpp" // pse:: and then the type traits

// just like TypeTraits.cpp but instead of passing in a type you pass in a value.
// It basically has the same mechanisms as TypeTraits.cpp, it does in fact because
// it defers it's work to the TypeTraits.cpp library.

namespace pse
{
	//template<auto T>
	//struct Add_Ref
	//{
	//	using value = Add_Ref<decltype(T)>::value; // defers work to Add_Ref defined in "Traits.cpp"
	//};
} // namespace pse