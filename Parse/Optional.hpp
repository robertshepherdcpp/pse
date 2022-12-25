#pragma once

namespace pse
{
	template<typename T>
	struct Optional
	{
		auto HasValue() -> bool
		{
			return _HasVal;
		}

		auto HasNothing() -> bool
		{
			return _HasNothing;
		}

		Optional()
		{
			_HasNothing = true;
			_HasVal = false;
		}

		Optional(T t)
		{
			_HasNothing = false;
			_HasVal = true;
		}

		auto GetVal() -> T
		{
			return Value;
		}


		operator bool()
		{
			return _HasVal;
		}

		auto operator!()
		{
			return _HasVal;
		}

		bool _HasNothing = true;
		bool _HasVal = false;

		T Value;
	};
} // namespace pse