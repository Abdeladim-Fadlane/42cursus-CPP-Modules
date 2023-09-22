#ifndef Brain_HPP
#define Brain_HPP
#include<string>
#include<iostream>
class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain& obj);
        Brain& operator = (const Brain &obj);
};
#endif