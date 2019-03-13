#ifndef MY_MATH_H
#define MY_MATH_H
#include <cmath>

template <class T>
constexpr T PI = T(3.1415926535897932385L);

constexpr double sqrt2 = std::sqrt(2.0);

template <class Number>
double div_1_sqrt_x(Number x)
{
    return  1.0 / std::sqrt(x);
}

template <class Number>
double cos_x_pow_2(Number x)
{
    return std::cos(x * x);
}

template <class Number>
double cos_e_pow_x(Number x)
{
    return std::cos(std::exp(x));
}


#endif // MY_MATH_H
