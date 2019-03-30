#include <QCoreApplication>
#include <iostream>
#include "auto_ptr.h"

struct Test
{
    int var;
    Test(int a_ = 0): var(a_){std::cout << "Test(int)" << std::endl;}
    Test(const Test& that):var(that.var){std::cout << "copy initialization" << std::endl;}
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    stu::auto_ptr<Test> b(new Test(9));
    std::cout << (*b).var;

    return a.exec();
}
