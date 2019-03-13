#include <QCoreApplication>
#include "test.h"
#include <map>
#include <string>
#include <iostream>
#include <functional>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::function<int(int,int)> sum = [](int a, int b){return a + b;};
    std::map<int,long long int> people_and_bird{{1, 80290000000},{2, 80295636348},{3, 802945889820}};
    std::cout << people_and_bird[2];
    //std::cout << sum(1,2);
    //test();
    return a.exec();
}
