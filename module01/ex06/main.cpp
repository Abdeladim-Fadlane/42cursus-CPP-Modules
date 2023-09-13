#include"Harl.hpp"

int main(int ac,char *av[])
{
    Harl harl;
    if(ac == 2)
        harl.complain((std::string) av[1]);
    else
        std::cout<<"You must enter one argement !\n";
}