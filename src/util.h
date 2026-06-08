#ifndef UTIL_H
#define UTIL_H
#include <math.h>
#include <iostream>
#include <type_traits>

namespace Util
{
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type degsToRads(T degs);
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type radsToDegs(T rads);
    template <typename T>
    typename std::enable_if<std::is_arithmetic<T>::value, T>::type squared(T value);
}

#endif