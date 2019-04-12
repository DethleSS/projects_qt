#ifndef LABA_6_H
#define LABA_6_H
#include <queue>
#include <iostream>
#include "queue.h"
template <class Iter>
void laba_6(Iter first, Iter last)
{
    Queue<int> q1;
    Queue<int> q0;
    int temp0 = 0;
    int temp1 = 0;

    for(auto i = first; i != last; ++i)
    {
        if(*i == 0)
        {
            q0.enqueue(*i);
            ++temp0;
        }
        else
        {
            q1.enqueue(*i);
            ++temp1;
        }
    }
    q0.printQueue();
    q1.printQueue();

}
#endif // LABA_6_H
