#pragma once

namespace pse
{
	struct Type
	{
		inline auto operator<=(Type& t);
		int i = 0;
		Type(int i) { i = 0; }
	};

	// just a move operation.
	auto Type::operator<=(Type& t)
	{
		i = t.i;
		t.i = 0;
	}
} // namespace pse