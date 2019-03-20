#ifndef _BINARY_SEARCH_
#define _BINARY_SEARCH_

template<class T>
const T* binary_search(T* first, T* last, const T& value)
{
    const T* lo = first, *hi = last, *mid;
    while(lo != hi)
    {
        mid = lo + (hi - lo) / 2;
        if(value == *mid)
                return mid;
        if(value < *mid)
                hi = mid;
        else
                lo = mid + 1;
    }
    return last;
}

#endif
