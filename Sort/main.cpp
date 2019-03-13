#include <QCoreApplication>
#include "sort.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#define print_conteiner(first, last) std::for_each(first, last, [](decltype(*first) a){std::cout << a << " ";})
int main(int argc, char *argv[])
{
    const int size = 10;
    QCoreApplication a(argc, argv);
    std::vector<int> v(size);
    std::vector<int> v1(size);
    std::iota(v.begin(), v.end(), 0);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    std::copy(v.begin(), v.end(), v1.begin());
    //print_conteiner(v.begin(), v.end());
    std::cout <<  stu::bubble_sort(v.begin(), v.end());
    std::cout<< std::endl;
    //std::cout << stu::comb(v1.begin(), v1.end());
    std::cout << std::endl;
    //print_conteiner(v.begin(), v.end());


    //std::cout << result.first << " ";
    //std::cout << result.second;
    return a.exec();
}

