#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include<string>
#include<iostream>
#include <stdint.h>



class  ScalarConverter
{
    public:
        ScalarConverter();
        ~ ScalarConverter();
        ScalarConverter(const  ScalarConverter&other);
        ScalarConverter &operator=(const  ScalarConverter&other);
};

#endif