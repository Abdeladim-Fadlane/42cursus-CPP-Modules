#include"Fixed.hpp"
Fixed::Fixed():numberValue(0)
{
};

Fixed::Fixed(const int n)
{
    this->numberValue = n << this->numberFranctional;
};

Fixed::Fixed(const float n)
{
    this->numberValue = roundf((float)(n * (1 << this->numberFranctional)));
};

Fixed::~Fixed()
{
};

Fixed& Fixed::operator=(const Fixed& obj)
{
    numberValue = obj.getRawBits();
    return(*this);
}

Fixed::Fixed( const Fixed& obj)
{
    *this = obj;
}

int Fixed::getRawBits( void ) const
{
    return(this->numberValue);
}

void Fixed::setRawBits(int const raw)
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

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed c1;
    c1.setRawBits(this->numberValue * other.numberValue / 256);
    return (c1);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed c1;
    if(other.numberValue == 0)
        return(c1);
    c1.setRawBits(this->numberValue  * 256 / other.numberValue );
    return (c1);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed c1;
    c1.setRawBits(this->numberValue - other.numberValue );
    return (c1);
}
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed c1;
    c1.setRawBits(this->numberValue + other.numberValue );
    return (c1);
}
///////////////////this is the way

bool Fixed::operator>(const Fixed &other) const
{

    return(this->numberValue > other.numberValue );
}
bool Fixed::operator<(const Fixed &other) const
{
    return(this->numberValue < other.numberValue );
}

bool Fixed::operator>=(const Fixed &other) const
{
    return(this->numberValue >= other.numberValue );
}
bool Fixed::operator<=(const Fixed &other) const
{
    return(this->numberValue <= other.numberValue );
}

bool Fixed::operator==(const Fixed &other) const
{
    return(this->numberValue == other.numberValue );
}

bool Fixed::operator!=(const Fixed &other) const
{
    return(this->numberValue != other.numberValue );
}


Fixed Fixed::operator++()//Pre-increment operator
{
    ++this->numberValue;
    return *this;
}

Fixed Fixed::operator++(int)//Post-increment operator
{
    Fixed tmp(*this);
    this->numberValue++;
    return tmp;
}

Fixed& Fixed:: min(Fixed& a, Fixed& b)
{
    if (a.numberValue < b.numberValue)
        return a;
    else 
        return b;
}
const Fixed& Fixed:: min(const Fixed&  a, const Fixed& b)
{
    if (a.numberValue < b.numberValue)
        return a;
    else 
        return b;
}

Fixed& Fixed:: max(Fixed& a, Fixed& b)
{
    if (a.numberValue > b.numberValue)
        return a;
    else 
        return b;
}

const Fixed& Fixed:: max(const Fixed&  a, const Fixed& b)
{
    if (a.numberValue > b.numberValue)
        return a;
    else 
        return b;
}