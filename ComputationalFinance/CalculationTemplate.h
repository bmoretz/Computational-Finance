#pragma once

namespace Common
{
    template <long N>
    struct Factorial
    {
        enum
        {
            result = Factorial<N - 1>::result * N
        };
    };

    template <>
    struct Factorial<0>
    {
        enum
        {
            result = 1
        };
    };
}