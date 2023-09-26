#include"Fixed.hpp"
Fixed::Fixed():numberValue(0)
{
    std::cout<<"Default constructor called\n";
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout<<"Copy assignment operator called\n";
    numberValue = obj.getRawBits();
    return(*this);
}

Fixed::Fixed( const Fixed& obj)
{
    std::cout<<"Copy constructor called\n";
    *this = obj;
}

int Fixed::getRawBits( void ) const
{
    return(this->numberValue);
}

void Fixed::setRawBits( int const raw )
{
    this->numberValue = raw;
}

//this is the way 

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called\n";
    this->numberValue = n * 256;
}

Fixed::Fixed(const float n)
{
    std::cout<<"Float constructor called\n";
    this->numberValue = roundf(n * 256);
}

float Fixed::toFloat( void ) const
{
    return((float)this->numberValue / 256);
}

int Fixed::toInt( void ) const
{
    return (this->numberValue / 256);
}

std::ostream&    operator<<(std::ostream &obj, const Fixed &other)
{
    obj << other.toFloat();
    return (obj);
}