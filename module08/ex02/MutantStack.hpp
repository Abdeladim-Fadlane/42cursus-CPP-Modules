#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include<iostream>
#include <stack>
#include<list>
#include <algorithm>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		class iterator : public std::deque<T>::iterator
		{
			public:
				iterator(const typename std::deque<T>::iterator &copy) : std::deque<T>::iterator(copy){}
		};

		MutantStack::iterator begin()
		{
			return iterator(this->c.begin());
		}

		MutantStack::iterator end()
		{
				return iterator(this->c.end());
		}
};

#endif