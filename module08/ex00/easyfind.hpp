#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include<iostream>
#include <vector>
#include<string.h>

template <typename T, typename U>
U easyfind(const T& container, U value)
{
    typename T::const_iterator it;
    for (it = container.begin(); it <container.end(); it++)
    {
        if (*it == value)
            return *it;
    }
    throw std::out_of_range("No occurrence found");
}

#endif