#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <string>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <conio.h>

std::string get_random_string(char first_l, char last_l, int size)
{
    std::string res;
    std::mt19937 gen;
    gen.seed(time(0));
    std::uniform_int_distribution<int> uid(first_l, last_l);
    for(int i = 0; i < size; ++i)
    {
        res.push_back(uid(gen));
    }
    return res;
}


#endif // GENERATOR_H
