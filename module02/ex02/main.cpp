#include"Fixed.hpp"

std::ostream    &operator<<(std::ostream &obj, const Fixed &other)
{
    obj << other.toFloat();
    return (obj);
}


#include <iostream>
int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    //std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
     std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

const int Fixed::numberFranctional = 8;
