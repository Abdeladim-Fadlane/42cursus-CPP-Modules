
#include"PhoneBook.hpp"


int main()
{
    PhoneBook phonebook;
    for(;;)
    {
        std::cout <<"\n**********MENU**********\n";
        std::cout <<"*                      *\n";
        std::cout <<"*--ADD--SEARCH--EXIT---*\n";
        std::cout <<"*                      *\n";
        std::cout <<"************************\n";
        std::string choice;
        if (!std::getline(std::cin, choice))
            break;
        else if (choice == "ADD")
            choiceAdd(phonebook);
        else if(choice == "SEARCH")
            choiceSearch(phonebook);
        else if(choice == "EXIT")
            break;
    }
    return 0;
}
