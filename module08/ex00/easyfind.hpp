#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include<iostream>
#include <vector>
#include<algorithm>
#include<list>
template <typename T>

void easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(),container.end(),value);
    if(it != container.end())
         std::cout<<*it<<": value is found .\n";
    else
        std::cerr<<value<<": value not found .\n";
}

#endif