#include <QCoreApplication>
#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include "alg.h"
#include <algorithm>
#include <iterator>
#include "dinamecheskiy_massive.h"
#include "vector.h"
#include "algorithms.h"
#include "sort.h"
#include <map>

struct Fill
{
    int value = 0;
    Fill() = default;
    Fill(int v): value(v){}
    int operator ()()
    {
        value += 2;
        return value;
    }
};

void f();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//        dinamichesky_massive array1(5);
//        dinamichesky_massive array2(5);
//        stu::fill_random(array1.begin(), array1.end(), 0, 10);
//        stu::fill_random(array2.begin(), array2.end(), 0, 20);
//        print_contenier(array1.begin(), array1.end());
//        std::cout<<std::endl;
//        print_contenier(array2.begin(), array2.end());
//        dinamichesky_massive map1;
//        for (auto i = array1.begin(); i != array1.end(); ++i)
//        {
//            if(*std::find(map1.begin(),map1.end(),*i) != *i)
//            {
//                map1.push_back(*i);
//            }
//        }
//        for (auto i = array2.begin(); i != array2.end(); ++i)
//        {
//            if(*std::find(map1.begin(),map1.end(),*i) != *i)
//            {
//                map1.push_back(*i);
//            }
//        }
//        stu::quick_sort(map1.begin(), map1.end(), [](int a, int b) {return a < b ;});
//        std::cout<<std::endl;
//        print_contenier(map1.begin(), map1.end());
    std::vector<int> v(10);
    stu::generate(v.begin(),v.end(),Fill(2));
    print_contenier(v.begin(),v.end());
    f();
    return a.exec();

}
void f(){std::cout << "Hello";}
