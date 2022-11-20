namespace pse
{
	// non templated type

	struct any_type_helper
	{
		// no implementation: just for when type any doesn't have a type.
	};

	struct any
	{
		any_type_helper ValueType;

		auto reset() -> bool { ValueType = any_type_helper{}; }
		auto is_set() -> bool { return _is_set; }

		friend struct any_type_helper;

		bool _is_set = false;
	};
} // namespace pse