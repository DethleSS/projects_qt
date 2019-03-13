#ifndef SORT_H
#define SORT_H
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include "algorithms.h"
namespace stu {

template <class Iter>
    int bubble_sort(Iter first, Iter last)
    {
        --last;
        bool is_sorted;
        std::size_t size = last - first;
        int result = 0;
        for(std::size_t i = 0; i != size; ++i)
        {
            is_sorted = true;
            for(Iter j = first, end = last - i; j != end; ++j)
            {
                ++result;
                if(*j > *(j + 1))
                {
                    is_sorted = false;
                    std::iter_swap(j, j + 1);
                }
            }
            if(is_sorted)
            {
                return result;
            }
        }
        return result;
    }

    template<class Iter>
    void insertion_sort(Iter first, Iter last)
    {
        for(; first != last; ++first)
        {

            std::iter_swap(first, stu::min_element(first, last));
        }
    }
template <class Iter>
    int comb(Iter first, Iter last)
     {

         int times = 0;
         double fakt = 1.2473309;
         int step = (last - first) - 1;

         while (step >= 1)
         {
             for (Iter i = first; i + step < last; ++i)
             {
                 ++times;
                 if (*i > *(i + step))
                 {
                     std::iter_swap(i, i + step);
                 }
             }
             step /= fakt;
         }
        return times;
     }

}



#endif // SORT_H
