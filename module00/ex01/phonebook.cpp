#include"PhoneBook.hpp"

int PhoneBook::check_index(int index)
{
    if (index >= 0 && index < numContacts)
        return(1); 
    return(0);
}

std::string    truncatedString(std::string str)
{
    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str += "."; 
    }
    return(str);
}

int PhoneBook::emtyField(const std::string fname,const std::string lname,
const std::string nname,const std::string number,const std::string secret)
{
    int index;
    std::istringstream iss(number) ;
    iss>>index;
    if(index <= 0)
        return(1);
    if(fname.empty() || number.empty() || lname.empty()
        || nname.empty()|| secret.empty() )
        return(1);
    return(0);
}

void PhoneBook::addContact(const std::string fname,const std::string lname,
const std::string nname,const std::string number,const std::string secret)
{
    if(emtyField(fname,lname,nname,number,secret) == 1)
        return ;
    Contact contact;
    contact.firstName = fname;
    contact.lastName = lname;
    contact.nikName = nname;
    contact.secret = secret;
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
        for (int i = 0; i < numContacts; i++)
        {
                int index = (old_index + i) % size;
                std::cout<<std::setw(10)   << i << "|"
                << std::setw(10) << contacts[index].firstName << "|"
                << std::setw(10) << contacts[index].lastName << "|"
                << std::setw(10) << contacts[index].nikName
                <<std::endl;    
        }
        std::cout<<"******************\n";
    }
    return (0);
}

void PhoneBook::display(int index)
{

        for(int i = 0;i < numContacts ;i++)
        {
            if(index == i)
            {
                int n = (old_index + i) % size;
                std::cout << "*****Search Contact*****" << std::endl;
                std::cout <<"Fist Name : " << contacts[n].firstName << std::endl;
                std::cout <<"last Name : " << contacts[n].lastName << std::endl;
                std::cout <<"NikName   : " << contacts[n].nikName << std::endl;
                std::cout <<"Secret    : " << contacts[n].secret << std::endl;
                std::cout <<"Number    : " << contacts[n].number << std::endl;
            } 
        }
}