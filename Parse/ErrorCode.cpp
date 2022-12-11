#pragma once

#include"String.cpp"

namespace pse
{
	struct ErrorCode
	{
		StringList m_str{};
		auto what() { return m_str; }

		ErrorCode(StringList str) { m_str = str; }
	};
} // namespace pse