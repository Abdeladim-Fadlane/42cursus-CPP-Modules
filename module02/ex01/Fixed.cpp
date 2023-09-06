#include"Fixed.hpp"
Fixed::Fixed():numberValue(0)
{
    std::cout<<"Default constructor called\n";
};

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called\n";
    this->numberValue = n << this->numberFranctional;
};

Fixed::Fixed(const float n)
{
    std::cout<<"Float constructor called\n";
    this->numberValue = roundf((float)(n * (1 << this->numberFranctional)));
};

Fixed::~Fixed()
{
    std::cout<<"Destructor called\n";
};

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

float Fixed::toFloat( void ) const
{
    return((float)this->numberValue / (1 << this->numberFranctional));
}

int Fixed::toInt( void ) const
{
    return (this->numberValue >> this->numberFranctional);
}
