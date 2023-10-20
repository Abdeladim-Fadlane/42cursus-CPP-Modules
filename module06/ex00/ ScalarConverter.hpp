#ifndef SCALARCONVERTER_HPP
#define  SCALARCONVERTER_HPP
#include<string>
#include<iostream>


class  ScalarConverter
{
    public:
        ScalarConverter();
        ~ ScalarConverter();
        ScalarConverter(const  ScalarConverter&other);
        ScalarConverter &operator=(const  ScalarConverter&other);
        static void    convert(std::string str); 
};

#endif