#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
int b = 255;
for(;b != 0; b = b << 1)
{
    std::cout<< b <<std::endl;
}
    return a.exec();
}
