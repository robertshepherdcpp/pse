#pragma once

namespace pse
{
	// this functions takes an error code from pse::ErrorCode and outputs it's meaning.
	// Everything new will also be added to the README.md part of the pse library

	const char* CodeMeaning(int x)
	{
		if (x == 026)
		{
			return "Out of Bounds Access.\n";
		}
		else if (054) // don't have another code number yet.
		{
			// No implementation yet.
			return "Invalid Type";
		}
		else if (076)
		{
			return "Not A Number (NaN)";
		}
		else if (84) // cannot put 8 here because it symbolises a base.
		{
			return "This Function Is No Longer In Use.";
		}
		else if (96) // same problem as with 084.
		{
			return "Your software is not supported.";
		}
		else if (034)
		{
			return "Your hardware is not supported.";
		}
	}
} // namespace pse