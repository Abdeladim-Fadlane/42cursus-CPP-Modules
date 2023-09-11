#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>
class Fixed
{
    private:
        int numberValue;
        static const int numberFranctional;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed operator *(const Fixed &other)const;
        Fixed operator/(const Fixed &other)const;
        Fixed operator+(const Fixed &other)const;
        Fixed operator-(const Fixed &other)const;
        bool operator>(const Fixed &other)const;
        bool operator<(const Fixed &other)const;
        bool operator>=(const Fixed &other)const;
        bool operator<=(const Fixed &other)const;
        bool operator==(const Fixed &other)const;
        bool operator!=(const Fixed &other)const;
        Fixed operator++();
        Fixed operator++(int);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed&  a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed&  a, const Fixed& b);
};

std::ostream    &operator<<(std::ostream &o, const Fixed &other);
#endif