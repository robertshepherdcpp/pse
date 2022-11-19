namespace pse
{
	// just inherit from all of the types then you can have all of the
	// copy assignment and constructors etc.
	template<typename T, typename... Ts>
	struct Variant : T, Ts...
	{
		// FIXME: Implement the Variant Body.
		// Needs the following:
		// - Current Member
		// - Get Value function
	};
} // namespace pse