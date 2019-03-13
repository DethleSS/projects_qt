#ifndef ALGORITHMS_H
#define ALGORITHMS_H

namespace stu {

template <class Iter>
Iter min_element(Iter first, Iter last)
{
    Iter min_el = first++;
    for(; first != last; ++first)
    {
        if(first < min_el)
        {
            min_el = first;
        }
    }
    return min_el;
}

}
#endif // ALGORITHMS_H
