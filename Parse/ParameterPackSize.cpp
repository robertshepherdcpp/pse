#pragma once

// #include"Globals.cpp"
// trying it eliminate an error
#include"Traits.cpp" // Traits::Is_Type<T>::value;

namespace pse
{
	int Parameter_Pack_Size__ = 0;

	template<typename T, typename... Ts>
	auto ParameterPackSize_(T t, Ts... ts)
	{
		Parameter_Pack_Size__ += 1;
		ParameterPackSize_(ts...);
	}

	template<typename T>
	auto ParameterPackSize_(T t)
		requires(Traits::Is_Type<T>::value)
	{
		Parameter_Pack_Size__ += 1;
		int _s = Parameter_Pack_Size__;
		Parameter_Pack_Size__ = 0; // reset for next invokation of this function
		return _s;
	}
}