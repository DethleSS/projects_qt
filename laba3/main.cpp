#include <QCoreApplication>

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <string>
#include <cstddef>
#include <ctime>
#include <fstream>
#include "generator.h"
#include <clocale>
#include "algorithms.h"

void open_and_write(std::string file_name,std::string str)
{
    std::ofstream out;
    out.open(file_name);
    out << str;
    out.close();
}

std::string read(std::string file_name)
{
    std::string temp;
    std::ifstream in;
    in.open(file_name);
    in >> temp;
    in.close();
    return temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_CTYPE, "rus");
        std::string temp = get_random_string(192, 255, 10);
        open_and_write("Hell.txt", temp);

        std::string temp1 = read("Hell.txt");
        std::cout << temp1 << std::endl;

        std::sort(temp1.begin(), temp1.end(), [](int a, int b){return a < b;});
        open_and_write("Hello.txt",temp1);
        std::cout << temp1 << std::endl;

    return a.exec();
}
