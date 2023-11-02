#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP
#include <climits>
#include<iostream>
#include <stack>

#include <algorithm>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
    using std::stack<T>::c;

    class iterator
    {
        private:
            typename std::deque<T>::iterator _ptr;

        public:
        iterator(typename std::deque<T>::iterator ptr) : _ptr(ptr) {}

        iterator& operator++() {
            ++_ptr;
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++_ptr;
            return tmp;
        }

        iterator& operator--()
        {
            --_ptr;
            return *this;
        }

        iterator operator--(int)
        {
            iterator tmp = *this;
            --_ptr;
            return tmp;
        }

        T& operator*()
        {
            return *_ptr;
        }

        bool operator==(const iterator& other) const
        {
            return _ptr == other._ptr;
        }

        bool operator!=(const iterator& other) const
        {
            return _ptr != other._ptr;
        }
    };

    iterator begin()
    {
        return iterator(c.begin());
    }

    iterator end()
    {
        return iterator(c.end());
    }
};


#endif