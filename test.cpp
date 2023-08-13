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

        void displayContacts()
        {
            if (numContacts == 0) {
                std::cout << "Phonebook is empty." << std::endl;
            } else {
                std::cout << "Phonebook Contacts:" << std::endl;
                for (int i = 0; i < numContacts; ++i) {
                    std::cout << i + 1 << ". Name: " << contacts[i].name << ", Number: " << contacts[i].number << std::endl;
                }
            }
        }

};

int main() {
    PhoneBook phonebook;

    phonebook.addContact("John Doe", "123-456-7890");
    phonebook.addContact("Jane Smith", "987-654-3210");
    phonebook.addContact("Alice Johnson", "555-123-4567");
    phonebook.addContact("Bob Brown", "111-222-3333");
    phonebook.addContact("Eve White", "444-555-6666");
    phonebook.addContact("Frank Black", "777-888-9999");
    phonebook.displayContacts();

    return 0;
}
