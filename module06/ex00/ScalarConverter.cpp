#include"ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const  ScalarConverter&other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const  ScalarConverter&other)
{
    (void)other;
    return(*this);
}

