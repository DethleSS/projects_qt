#include <QCoreApplication>
#include "list.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    stu::list<int> b{1,-2,3};
//    auto r = std::find(b.begin(), b.end(),-2);
//    b.insert_after(r,4);
//    for(auto i = b.begin(); i != b.end(); ++i)
//    {
//        std::cout << *i <<" ";

//    }
    for(auto i = b.begin(); i != b.end(); ++i)
    {
        std::cout << *i;
    }
//    std::cout << b.find_last()->m_value;
//    std::cout << (b.begin() == b.end());
//    std::cout << b.head->m_value <<" ";
//    std::cout << b.head->next->m_value;
    return a.exec();
}
