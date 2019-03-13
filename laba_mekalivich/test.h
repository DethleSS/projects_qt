#ifndef TEST_H
#define TEST_H
#include <cmath>
#include <iostream>
#include <functional>
#include "my_math.h"

#define inscribed(a) (a) / 2.0
#define circumscribed(a) a / std::sqrt(2)

template <class Number>
Number circumference (Number d)
{
    Number r = d / 2;
    return 2 * PI<Number> * r;
}

std::function<double(int)> area_of_a_circle = [](int d)
{
    double r = d / 2;
    return PI<double> * std::pow(r, 2);
};

void test()
{
    std::cout<< area_of_a_circle(4.5);
}
#endif // TEST_H
