#ifndef UTIL_H
#define UTIL_H
#include <math.h>
#include <iostream>

namespace Util
{
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::T degsToRads(T degs);
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::T radsToDegs(T rads);
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::T squared(T value);
}

#endif