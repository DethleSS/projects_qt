#include <QCoreApplication>
#include "stack.h"
#include "laba5.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> b{1,2,3,4,5,6};
    std::string s = "qwhrrewq";
    std::cout << is_polindrom(s.begin(),s.end());


    return a.exec();
}
