#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#define SIZE 8


class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nikName;
        std::string secret;
        std::string number;
};

class PhoneBook
{
    private:
        Contact contacts[SIZE];
        int numContacts;
        int old_index;
    public:
        
        PhoneBook():numContacts (0),old_index (0){}
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

