#pragma once

namespace pse
{
    enum class endian
    {
      #ifdef _WIN32
          little = 0,
          big = 1,
          native = little
      #else
          little = __ORDER_LITTLE_ENDIAN__,
          big = __ORDER_BIG_ENDIAN__,
          native = __BYTE_ORDER__
      #endif
    };

    template<bool bit>
    struct bit_type
    {
        static constexpr int bint = bit;
    };

    template<auto Bit>
    struct bit
    {
        bit_type b{ Bit };
    };
} // namespace pse