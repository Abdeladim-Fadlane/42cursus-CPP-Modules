
#include"PhoneBook.hpp"


int main()
{
    PhoneBook phonebook;
    for(;;)
    {
        std::cout << "Choise :\n. ADD \n. SEARCH \n. EXIT\n";
        std::string choice;
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        else if (choice == "DISPLAY")
        {
            phonebook.display();
        }
        else if (choice == "ADD")
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
            phonebook.displayContacts();
        }
        else if(choice == "EXIT")
            break;
    }
    return 0;
}
