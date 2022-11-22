#pragma once

namespace pse
{
	template<typename ReturnType, typename Parameter>
	struct Function
	{
		decltype(ReturnType(Parameter)) function = ReturnType(Parameter) { return {}; };
	};
} // namespace pse