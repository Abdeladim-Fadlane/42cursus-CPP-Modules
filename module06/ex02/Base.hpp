#ifndef BASE_HPP
#define BASE _HPP
#include<string>
#include<iostream>
#include <stdint.h>

class  Base
{
    public:
        virtual ~Base();
};
void identify(Base& p);
void identify(Base* p);
Base * generate(void);
#endif