#ifndef _BINARY_SEARCH_
#define _BINARY_SEARCH_

template<class T>
const T* binary_search (const T* array, int n, const T& x)
{
    const T* lo = array, *hi = array + n, *mid;
    while(lo != hi)
    {
        mid = lo + (hi - lo) / 2;
        if(x == *mid)
                return mid;
        if(x < *mid)
                hi = mid;
        else
                lo = mid + 1;
    }
    return array + n;
}

#endif
