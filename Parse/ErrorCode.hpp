#pragma once

#include"StringList.hpp"

namespace pse
{
	struct ErrorCode
	{
		int code = 0;
		StringList m_str{};
		auto what() { return m_str; }

		ErrorCode(StringList str) { m_str = str; }
		ErrorCode() {}
		ErrorCode(int x) { code = x; }
	};
} // namespace pse