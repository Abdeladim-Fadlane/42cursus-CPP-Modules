
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
        {
            std::cout << "Exit.\n";
            break;
        }
        else if (choice == "a")
        {
            std::string fName, phone,lName,nName,secret;

            std::cout << "Enter First name: ";
            std::getline(std::cin ,fName);

            std::cout << "Enter last name: ";
            std::getline(std::cin ,lName);

            std::cout << "Enter Nickname: ";
            std::getline(std::cin ,nName);

            std::cout << "Enter Darkest secret: ";
            std::getline(std::cin ,secret);
           
 
            std::cout << "Enter Phone number: ";
            std::getline(std::cin ,phone);

            fName = truncatedString(fName);
            lName = truncatedString(lName);
            nName = truncatedString(nName);
           
            phonebook.addContact(fName,lName,nName,phone,secret);
        }
        else if(choice == "s")
        {
            if(!phonebook.displayContacts())
            {
                for(;;)
                {
                    std::string buff;
                    std::cout<<"Enter index\n";
                    if(!std::getline(std::cin,buff))
                    {
                        std::cout << "EXIT.\n";
                        break;
                    }
                    int index;
                    std::istringstream iss(buff);
                    iss >> index;
                    if(phonebook.check_index(index) == 0)
                    {
                        std::cout<<"index out of rang !!"<<std::endl;
                        break;
                    }
                    phonebook.display(index);
                    break;
                }
            }
        }
        else if(choice == "e")
            break;
    }
    return 0;
}
