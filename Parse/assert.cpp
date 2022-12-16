#pragma once

// Made noexcept so that the compiler will stop when this assertion fails.
// If it is marked noexcept and throws, execution should stop.
auto assert(bool b) noexcept
{
	if (!b) throw b;
}

auto assert(bool b, auto* c)
{
	if (!b) throw c;
}