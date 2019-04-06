#ifndef LABA5_H
#define LABA5_H
#include "stack.h"
#include <iostream>
template <class Iter>
bool is_polindrom(Iter first, Iter last)
{
    stu::stack<int> b;
    for(auto i = first; i != last; ++i)
    {
        b.push(*i);
    }
    for(auto i = first; i != last; ++i)
    {
        if(*i != b.top())
        {
            return false;
        }

        b.pop();
    }
    return true;
}

#endif // LABA5_H
