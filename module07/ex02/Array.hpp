#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

template <typename T>

class Array
{
    private:
        unsigned int _n;
        T *_arr;
    public:
        Array()
        {
            _n = 0;
            _arr = NULL;
        }
        ~Array()
        {
            delete[] _arr;
        }
        Array(unsigned int n)
        {
            this->_n = n;
            _arr = new T[_n];
        }
        Array(const Array<T> &other)
        {
            this->_n = other._n;
            _arr = new T[_n];
            for(unsigned int i = 0;i < _n ;i++)
            {
                this->_arr[i] = other._arr[i];
            }
        }
        Array<T> &operator=(const Array<T> &other)
        {
            delete[] this->_arr;
            this->_n = other._n;
            _arr = new T[_n];
            for(unsigned int i = 0;i < _n ;i++)
            {
                this->_arr[i] = other._arr[i];
            }
            return *this;
        }
        T & operator[](unsigned int index)
        {
            if(index < 0 || index >= this->_n)
                throw std::out_of_range("Index is out of bounds");
            return _arr[index];
        }
        unsigned int size() const
        {
            return _n;
        }
};

#endif