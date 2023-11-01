#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>


template <typename T, typename N>

void iter(T addressArray[], unsigned int lengthArray, N func)
{
    for (unsigned int i = 0; i < lengthArray; i++)
    {
        func(addressArray[i]); 
    }
}

#endif
