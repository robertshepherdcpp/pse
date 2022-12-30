namespace pse
{
	struct Error
	{
	};

	template<typename T>
	struct Error_Or
	{
		Error_Or(Error& e) { Error_Val = true; }
		Error_Or(T& t) { Error_Val = false; }

		bool Error_Val{false};
		T Value_;
		Error Error_;
		auto get() { return Error_Val == true ? Error_ : Value_; }
	};
} // namespace pse