
#include"PhoneBook.hpp"

void   choiceAdd(PhoneBook& phonebook)
{
    std::string fName, phone,lName,nName,secret;
    std::cout << "Enter First name: ";
    if (!std::getline(std::cin ,fName))
            exit(1);              
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin ,lName))
            exit(1);  
    std::cout << "Enter Nickname: ";
    if(!std::getline(std::cin ,nName))
            exit(1);
    std::cout << "Enter Darkest secret: ";
    if (!std::getline(std::cin ,secret))
            exit(1);          
    std::cout << "Enter Phone number: ";
    if (!std::getline(std::cin ,phone))
            exit(1);
    phonebook.addContact(fName,lName,nName,phone,secret);
}

int    convertToint(std::string str)
{
    int i = 0;
    int re = 0;
    if(str[i] == '+')
        i++;
    while(i < (int)str.length())
    {
        if(str[i] < '0' || str[i] > '9')
            return(-1);
        i++;
    }
    i = 0;
    if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        re = re *10 + str[i] - '0';
        i++;
    }
    return(re);
}

void    choiceSearch(PhoneBook& phonebook)
{
    if(!phonebook.displayContacts())
    {
        for(;;)
        {
            std::string buff;
            std::cout<<"Enter index : ";
            if(!std::getline(std::cin,buff))
                break;
            int index = convertToint(buff);
           
            if(phonebook.check_index(index) == 0)
            {
                std::cout<<"\n\033[1;31mAlert! Wrong index !!\033[0m "<<std::endl;
                break;
            }
            phonebook.display(index);
            break;
        }
    }
}

int PhoneBook::displayContacts()
{
    if (numContacts == 0)
    {
        std::cout <<"Phonebook is empty." << std::endl;
        return (1);
    }
    else
    {
        std::cout << "*****Phonebook Contacts*****" << std::endl;
        std::cout<< std::setw(10) <<"Index"<< "|"
        << std::setw(10) << "First Name"<< "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "NikName" << std::endl;
        for (int i = 0; i < count; i++)
        {
                std::cout<<std::setw(10) << i << "|"
                << std::setw(10) << truncatedString(contacts[i].getFirstName()) << "|"
                << std::setw(10) << truncatedString(contacts[i].getLastName())<< "|"
                << std::setw(10) << truncatedString(contacts[i].getNikName())
                <<std::endl;    
        }
        std::cout<<"******************\n";
    }
    return (0);
}

void PhoneBook::display(int index)
{
        for(int i = 0;i < count ;i++)
        {
            if(index == i)
            {
                std::cout << "*****Search Contact*****" << std::endl;
                std::cout <<"Fist Name : " << contacts[i].getFirstName() << std::endl;
                std::cout <<"last Name : " << contacts[i].getLastName()<< std::endl;
                std::cout <<"NikName   : " << contacts[i].getNikName() << std::endl;
                std::cout <<"Secret    : " << contacts[i].getSecret()<< std::endl;
                std::cout <<"Number    : " << contacts[i].getNumber() << std::endl;
            } 
        }
}

PhoneBook::PhoneBook()
{
    numContacts = 0;
    old_index = 0;
    count = 0;
};
