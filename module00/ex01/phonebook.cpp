#include"PhoneBook.hpp"

int PhoneBook::check_index(int index)
{
    if (index >= 0  && index < numContacts)
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
int my_atoi(std::string number)
{
    int i = 0;
    while(i < (int)number.length())
    {
        if(number[i] > 47 && number[i] < 58)
            return(1);
        i++;
    }
    return(0);
}
int PhoneBook::emtyField( std::string fname,std::string lname,
const std::string nname, std::string number, std::string secret)
{
    if(my_atoi(number) == 0)
        return(2);
    std::string buff[5] = {fname,nname,secret,lname,number};
    int i = 0;
    int j = 0;
    while(i < 5)
    {
        j = 0;
        if(buff[i].length() == 0 || !buff[i].compare(" "))
            return(1);
        while(j < buff[i][j])
        {
            if(!isprint(buff[i][j]))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

void PhoneBook::addContact(const std::string fname,const std::string lname,
const std::string nname,const std::string number,const std::string secret)
{   
    int i = emtyField(fname,lname,nname,number,secret) ;
    if(i == 2)
    {
        std::cout<<"\n\033[1;31mALERT! The number must containes olny digits !!\033[0m \n";
        return ;
    } 
    if(i == 1)
    {
        std::cout<<"\n\033[1;31mALERT! Can't save contact whit emty field !!\033[0m\n";
        return ;
    }
    Contact contact;
    contact.setFirstName(fname);
    contact.setLastName(lname);
    contact.setNikName(nname);
    contact.setNumber(fname);
    contact.setSecret(fname);
    // contact.firstName = fname;
    // contact.lastName = lname;
    // contact.nikName = nname;
    // contact.secret = secret;
    // contact.number = number;
    if (numContacts > SIZE - 1)
    {
        numContacts = 0;

    }
    contacts[numContacts] = contact;
    numContacts++;
    count++;
    if (count > SIZE )
        count = SIZE ;
    std::cout<<"\033[1;32m\nContact saved successfully!\033[0m\n";
}
