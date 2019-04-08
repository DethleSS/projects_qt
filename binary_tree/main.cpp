#include <QCoreApplication>
#include "binary_tree.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    stu::Binary_tree b;
    b.insert(4);
    b.insert(2);
    b.insert(6);

    b.print_all();
    //std::cout << b.size();
    std::cout << b.contains(2);



    return a.exec();
}
