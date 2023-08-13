#include <iostream>
#include <iomanip>
#define size 8
class Contact {
    public:
        std::string name;
        std::string number;
};

class PhoneBook
{
    private:
        Contact contacts[size];
        int numContacts;
        int old_index;
    public:
        PhoneBook()
        {
            numContacts = 0;
            old_index = 0;
        }
        int emtyField(const std::string name, const std::string number)
        {
            if(name.empty() || number.empty())
                return(1);
            return(0);
        }
        void addContact(const std::string name, const std::string number)
        {
            if(emtyField(name,number) == 1)
                return ;
            Contact contact;
            contact.name = name;
            contact.number = number;

            if (numContacts < size)
            {
                contacts[numContacts] = contact;
                numContacts++;
            } else
            {
                contacts[old_index] = contact;
                old_index = (old_index + 1) % size;
            }
        }
        void displayContacts()
        {
            if (numContacts == 0)
            {
                std::cout <<"Phonebook is empty." << std::endl;
            } else
            {
                std::cout << "Phonebook Contacts:" << std::endl;
                for (int i = 0; i < numContacts; i++)
                {
                        int index = (old_index + i) % size;
                        std::cout << std::setw(2) << i + 1 << ". "
                        << std::setw(20) << contacts[index].name << " | "
                        << std::setw(15) << contacts[index].number << std::endl;
                }
            }
        }
        void display()
        {
            for(int i = 0;i < numContacts ;i++)
            {
                int index = (old_index + i) % size;
                std::cout << "Phonebook Contacts:" << std::endl;
                std::cout << i+1  << ". Name: " << contacts[index].name << " | Number: " << contacts[index].number << std::endl;
                //std::cout << "Phonebook Contacts:" << std::endl;
            }
        }
};


