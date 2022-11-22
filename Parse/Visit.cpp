#pragma once

namespace pse
{
	// FIXME: Make own header file for the choices namespace
	namespace Choices
	{
		struct ReturnWanted {};
		struct ReturnUnWanted {};
	}; // namespace Choices

	template<typename Callable, typename... Parameters>
    auto Visit(Callable& c, Choices::ReturnWanted, Parameters... parameters)
	{
		return c(parameters...);
	}

	template<typename A, typename B, template<typename A, typename B> typename Callable, typename Parameter>
	auto Visit(Callable<A, B>& c, Choices::ReturnUnWanted, Parameter parameter)
	{
		c(parameter);
	}

	template<typename Callable, typename... Parameters>
	auto Visit(Callable& c, Choices::ReturnUnWanted, Parameters&... parameters)
	{
		c(parameters...);
	}

	template<typename Callable, typename Parameters>
	auto Visit(Callable& c, Choices::ReturnWanted, Parameters parameters)
	{
		return c(parameters);
	}

	template<typename Callable, typename Parameters>
	auto Visit(Callable& c, Choices::ReturnUnWanted, Parameters& parameters)
	{
		c(parameters);
	}

	template<typename Callable>
	auto Visit(Callable& c, Choices::ReturnWanted)
	{
		return c();
	}

	template<typename Callable>
	auto Visit(Callable& c, Choices::ReturnUnWanted)
	{
		c();
	}
}