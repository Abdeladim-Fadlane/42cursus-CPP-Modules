#include"PhoneBook.hpp"

std::string Contact::getFirstName()
{
    return(firstName);
}
std::string Contact::getLastName()
{
    return(lastName);
}
std::string Contact::getNikName()
{
    return(nikName);
}
std::string Contact::getSecret()
{
    return(secret);
}
std::string Contact::getNumber()
{
    return(number);
}
void Contact::setFirstName(std::string str)
{
        firstName=str;
}
void Contact::setLastName(std::string str)
{
        lastName=str;
}
void Contact::setNikName(std::string str)
{
        nikName=str;
}
void Contact::setSecret(std::string str)
{
        secret=str;
}
void Contact::setNumber(std::string str)
{
        number=str;
}