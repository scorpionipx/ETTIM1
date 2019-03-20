//Header inclus numai pentru macrodefinitai lui NULL.
#include <stddef.h>

//Algoritmul nu-si propune modificarea valorilor din container.
//Nici a elementului a carui adresa este returnata ...
const int* binary_search (const int* array, int n, int x)
{
    //Nici a vreunui alt element ...
    //Modificarea valorii vreunui pointer este alceva ...
    const int* lo = array, *hi = array + n, *mid;
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
    return NULL;
}

