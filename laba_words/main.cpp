#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "slovari.h"
#define create_function(Iter, name) void name(Iter first, Iter last){\
    for(; first != last; ++first)\
{\
    std::cout << *first << " " ;\
}\
}

create_function(std::vector<int>::iterator, f1);

auto main(I argc, char *argv[])->I
{
    QCoreApplication a(argc, argv);
    //int array [5]{1,2,3,4,5};
    std::vector<int> v1{1,2,3,4,5};
    f1(v1.begin(),v1.end());



    return a.exec();
}
