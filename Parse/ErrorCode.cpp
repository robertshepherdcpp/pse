#pragma once

#include"String.cpp"

namespace pse
{
	struct ErrorCode
	{
		StringList str{};
		auto what() { return str; }
	};
} // namespace pse