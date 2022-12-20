#pragma once

namespace pse
{
    template<typename First, class size, typename Last>
    Last copy_n(First first, size count, Last result)
    {
        if (count > 0) {
            *result++ = *first;
            for (size i = 1; i < count; ++i) {
                *result++ = *++first;
            }
        }
        return result;
    }
} // namespace pse