#include <util.h>
#include <math.h>

namespace Util
{
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type degsToRads(T degs)
    {
        return degs * M_PI / 180.0;
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type radsToDegs(T rads)
    {
        return rads * 180.0 / M_PI;
    }

    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type squared(T value)
    {
        return value * value;
    }
}