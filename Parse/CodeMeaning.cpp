#pragma once

namespace pse
{
	// this functions takes an error code from pse::ErrorCode and outputs it's meaning.
	// Everything new will also be added to the README.md part of the pse library

	auto CodeMeaning(int x) -> decltype(auto)
	{
		if (x == 026)
		{
			return "Out of Bounds Access.\n";
		}
		else if (false/*Other code number*/) // don't have another code number yet.
		{
			// No implementation yet.
		}
	}
} // namespace pse