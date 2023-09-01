#ifndef FIXED_HPP
#define FIXED_HPP
#endif
#include <iostream>
class Fixed
{
    private:
        int numberValue;
        static const int numberFranctional = 8;
    public:
        Fixed();
        Fixed(Fixed& obj);
        Fixed& operator=(const Fixed&);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};