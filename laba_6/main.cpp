#include <QCoreApplication>
#include "queue.h"
#include <string>
#include "laba_6.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string str{1,0,1,1,0,0,0,1};
    laba_6(str.begin(),str.end());
    return a.exec();
}
