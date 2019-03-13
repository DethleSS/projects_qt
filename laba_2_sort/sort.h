#ifndef SORT_H
#define SORT_H
#include <algorithm>
#include <functional>
#include <iterator>

namespace stu
{

template<typename BidirectionalIterator, typename Compare >
void quick_sort( BidirectionalIterator first, BidirectionalIterator last, Compare cmp)
{
  if( first != last ) {
    BidirectionalIterator left  = first;
    BidirectionalIterator right = last;
    BidirectionalIterator pivot = left++;

    while( left != right ) {
      if( cmp( *left, *pivot ) ) {
         ++left;
      } else {
         while( (left != --right) && cmp( *pivot, *right ) )
           ;
         std::iter_swap( left, right );
      }
    }
    --left;
    std::iter_swap( first, left );

    quick_sort( first, left, cmp );
    quick_sort( right, last, cmp );
  }
}


}




#endif // SORT_H
