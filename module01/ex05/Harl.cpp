#include"Harl.hpp"

void Harl::debug( void )
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
    std::cout<<"I really do!\n\n";
}
void Harl::info( void )
{
    std::cout<<"I cannot believe adding extra bacon costs more money.\n";
    std::cout<<"You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}
void Harl::warning( void )
{
    std::cout<<"I think I deserve to have some extra bacon for free.\n";
    std::cout<<"I’ve been coming foryears whereas you started working here since last month.\n\n";
}
void Harl::error( void )
{
    std::cout<<"This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
    void (Harl::*p[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    std::string str[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; ++i)
    {
        if (level == str[i])
        {
            (this->*p[i])();
            return;
        }
    }
    std::cout << "Invalid complaint level.\n\n";
}