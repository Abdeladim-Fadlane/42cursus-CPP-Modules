#include"Fixed.hpp"

Fixed::Fixed():numberValue(0)
{
    std::cout<<"Default constructor called\n";
};

Fixed::~Fixed()
{
    std::cout<<"Destructor called\n";
};

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout<<"Copy assignment operator called \n";
    this->numberValue = obj.getRawBits();
    return(*this);
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout<<"Copy constructor called\n";
    *this = obj;
}

int Fixed::getRawBits( void ) const
{
    std::cout<<"getRawBits member function called\n";
    return(numberValue);
}

void Fixed::setRawBits( int const raw )
{
    numberValue = raw;
}
