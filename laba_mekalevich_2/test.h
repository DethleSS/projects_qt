#ifndef TEST_H
#define TEST_H
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <iostream>

using UF = double (*)(double);

std::vector<UF> v1{
    [](double x){return (std::exp(x) - std::exp(-x))/2;},
    [](double x){return std::pow(x, 2);}

};

std::map<std::string,std::function<double(double)>> v2{
    {"sh(x)",[](double x){return (std::exp(x) - std::exp(-x))/2;}},
    {"pow(x,2)",[](double x){return std::pow(x, 2);}}
};



double z_f()
{
    std::cout << v2["sh(x)"](3.8);
}

void test()
{
    z_f();
}
#endif // TEST_H
