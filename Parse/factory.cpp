#pragma once

namespace pse
{
	namespace detail
	{
		struct parameter_pack {};
		struct constructor {};
	}

	template<typename Class, detail::constructor& p_p, auto&&... Args>
	struct factory_constructor_non_typename
	{
		auto operator()()
		{
			return Value;
		}

		Class Value{ Args... };
	};

	
	template<typename Class, detail::parameter_pack& c, auto&&... Args>
	struct factory_parameter_pack_non_typename
	{
		auto operator()()
		{
			return Value;
		}

		Class Value = Class{ Args... };
	};
	

	template<typename Class, detail::constructor& c, typename... Args>
	struct factory_construct_typename
	{
		auto operator()(Args... args)
		{
			return Class{ args... };
		}
	};

	template<typename Class, detail::parameter_pack& p_p, typename... Args>
	struct factory_parameter_pack_typename
	{
		constexpr auto operator()(Args... args)
		{
			return Class{args...};
		}
	};
} // namespace pse