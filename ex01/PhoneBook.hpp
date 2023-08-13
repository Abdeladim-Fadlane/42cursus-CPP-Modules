#include <iostream>

class Contact {
    public:
        std::string name;
        std::string number;
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int numContacts;
    public:
            PhoneBook()
            {
                numContacts = 0;
            }

        void addContact(const std::string name, const std::string number)
        {
            Contact contact;
            contact.name = name;
            contact.number = number;

            if (numContacts < 8) {
                contacts[numContacts] = contact;
                numContacts++;
            } else {
                for (int i = 0; i < 7; ++i) {
                    contacts[i] = contacts[i + 1];
                }
                contacts[7] = contact;
            }
        }

        void displayContacts(std::string name)
        {
            if (numContacts == 0) {
                std::cout << "Phonebook is empty." << std::endl;
            } else {
                std::cout << "Phonebook Contacts:" << std::endl;
                for (int i = 0; i < numContacts; i++)
                {
                    if(contacts[i].name == name)
                        std::cout << i  << ". Name: " << contacts[i].name << ", Number: " << contacts[i].number << std::endl;
                }
            }
        }
};