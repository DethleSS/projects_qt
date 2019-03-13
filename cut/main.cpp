#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include <russian.h>


void f(int* arr,int size, int a , int b){
    arr[0] = a;
    arr[1] = b;
    for(int i = 2 ; i < size ; ++i){
        arr[i] = arr[i-1] * arr[i-2];
    }
}

int min_el(int* arr , int size){
    int min_ = arr[0];
    for( int i = 0; i < size; ++i){
        if(min_ > arr[i] ){
            min_ = arr[i];
        }
    }
    return min_;
}

int max_el(int* arr , int size){
    int max_ = arr[0];
    for( int i = 0; i < size; ++i){
        if(max_ < arr[i] ){
            max_ = arr[i];
        }
    }
    return max_;
}
template<class Matrix>
void f1(Matrix matrix,int column , int row){
    for(int i = 0;i < column ; ++i){
        std::cout << min_el(*(matrix + i), row) << std::endl;
        std::cout << max_el(*(matrix + i), row) << std::endl;
    }
}
double math_function(double x){
    return (std::pow(x,2) + 9) / std::tan(sqrt(x));
}
bool comp(double a , double b){
    return math_function(a) < math_function(b);

}
template<class Iter , class Comp>
Iter min_el(Iter first , Iter last, Comp comp){
    Iter min_ = first++;
    for(;first != last; ++first){
        if(comp(*first, min_)){
            min_ = first;
        }
    }
    return min_;
}


template <class Matrix>
void f4(Matrix matrix ,int column, int row)
{
    std::vector<int> v1;
    for(int i = 0; i != column - 1; ++i)
    {
        for(int j = 1 + i; j != row; ++j)
        {
           v1.push_back(matrix[i][j]);
        }
    }
    std::for_each(v1.begin(), v1.end(), [](int a){std::cout << a << std::endl;});
}

template <class Iter>
void f(Iter first, Iter last, int a, int b)
{
    *first++ = a;
    *first++ = b;
    for(;first != last; ++first)
    {
        *first = *(first - 1) * *(first - 2);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //int arr1 [3][3] {{2,5,9},{5,6,1},{1,2,3}};
    //f4(arr1, 3, 3);
    int arr[5]{0};
    f(arr, arr + 5, 1, 2);
    for(int i = 0; i != 5; ++i)
    {
        std::cout << arr[i];
    }


    return a.exec();
}
