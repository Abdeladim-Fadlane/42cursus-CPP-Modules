#ifndef PHONRBOOK_HPP
#define PHONRBOOK_HPP
#endif
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<string>
#define SIZE 8


class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nikName;
        std::string secret;
        std::string number;
    public:
        std::string getFirstName();
        std::string getLastName();
        std::string getNikName();
        std::string getSecret();
        std::string getNumber();
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNikName(std::string str);
        void setSecret(std::string str);
        void setNumber(std::string str);
};

class PhoneBook
{
    private:
        Contact contacts[SIZE];
        int numContacts;
        int old_index;
        int count;
    public:
        PhoneBook();
        int emtyField(const std::string fname,const std::string lname,
        const std::string nname,const std::string number,const std::string secret);
        void addContact(const std::string fname,const std::string lname,
        const std::string nname,const std::string number,const std::string secret);
        int displayContacts();
        void display(int index);
        int check_index(int index);
};
std::string    truncatedString(std::string str);
void   choiceAdd(PhoneBook& phonebook);
void    choiceSearch(PhoneBook& phonebook);

