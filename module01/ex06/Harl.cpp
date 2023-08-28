#include"Harl.hpp"

void Harl::debug( void )
{
    std::cout<<"[ DEBUG ]\n";
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
    std::cout<<"I really do!\n\n";
}
void Harl::info( void )
{
    std::cout<<"[ INFO ]\n";
    std::cout<<"I cannot believe adding extra bacon costs more money.\n";
    std::cout<<"You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}
void Harl::warning( void )
{
    std::cout<<"[ WARNING ]\n";
    std::cout<<"I think I deserve to have some extra bacon for free.\n";
    std::cout<<"I’ve been coming foryears whereas you started working here since last month.\n\n";
}
void Harl::error( void )
{
    std::cout<<"[ ERROR ]\n";
    std::cout<<"This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
    std::string str[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int i = 1;
    while(i < 4)
    {
        if (level == str[i])
            break;
        i-=-1;
    }
    switch (i)
    {
        case    0:
            debug();
            info();
            warning();
            error();
            break;
        case    1:
            info();
            warning();
            error();
            break;
        case    2:
            warning();
            error();
            break;
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}


