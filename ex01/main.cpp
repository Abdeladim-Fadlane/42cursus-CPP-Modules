
#include"PhoneBook.hpp"


int main() {
    PhoneBook phonebook;
    
    while(1337)
    {
        std::cout << "1 . Add Contact\n2 . Search Contact\n3 . Exit\n";
        std::string choice;
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        if (choice == "ADD")
        {
            std::string name, phone;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter phone number: ";
            std::cin >> phone;
            phonebook.addContact(name, phone);
        }
        else if(choice == "SEARCH")
        {
            std::string search_name;
            std::cout << "Enter search name: ";
            std::cin >> search_name;
            phonebook.displayContacts(search_name);
        }
        else if(choice == "EXIT")
            break;
    }
    return 0;
}
