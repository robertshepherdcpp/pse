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

	// using namespace Traits; Not considered best practice, so i will not do it.

	template<auto T>
	struct Add_Const
	{
		using T_type = decltype(T);
		using value = Traits::Add_Const<T_type>::value;
		T_type value_t = value{};
	};

	template<auto T>
	struct Add_Ref
	{
		using T_type = decltype(T);
		using value = Traits::Add_Ref<T_type>::value;
		T_type value_t = value{};
	};

	template<auto T>
	struct Add_Pointer
	{
		using T_type = decltype(T);
		using value = Traits::Add_Pointerf<T_type>::value;
		T_type value_t = value{};
	};

	template<auto T>
	struct Rvalue_Ref
	{
		using T_type = decltype(T);
		using value = Traits::Add_Rvalue_Ref<T_type>::value;
		T_type value_t = value{};
	};
} // namespace pse