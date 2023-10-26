#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>


template <typename T, typename U, typename N>

void iter(T addressArray[], U lengthArray, N func)
{
    for (U i = 0; i < lengthArray; i++)
    {
        func(addressArray[i]); 
    }
}

#endif