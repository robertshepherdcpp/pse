#include<ranges>

namespace pse
{
  template<auto X>
  constexpr auto range() -> decltype(auto)
  {
    return std::ranges::views::iota(0) | std::ranges::views::take(X);
  }
};
