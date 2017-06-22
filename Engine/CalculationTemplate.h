#pragma once

namespace NumericalMethods
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

    template<int N, int P>
    struct ChoiceNumber
    {
        enum
        {
            result = Factorial<N>::result / ( Factorial<P>::result * Factorial<N-P>::result )
        };
    };
}