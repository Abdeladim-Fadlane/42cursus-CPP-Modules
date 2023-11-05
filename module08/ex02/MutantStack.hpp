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
		MutantStack():std::stack<T>(){};
		~MutantStack(){};
		MutantStack(const MutantStack &other):std::stack<T>(other){};
		MutantStack & operator=(const MutantStack &other)
		{
			std::stack<T>::operator=(other);
			return *this;
		}
		class iterator : public std::deque<T>::iterator
		{
			public:
				iterator(){};
				~iterator(){};
				iterator(const typename std::deque<T>::iterator &other):std::deque<T>::iterator(other){};
				iterator& operator=(const iterator & other)
				{
					std::deque<T>::iterator::operator=(other);
					return *this;
				};
		};
		iterator begin()
		{
			return iterator(this->c.begin());
		}
		iterator end()
		{
			return iterator(this->c.end());
		}
};

#endif