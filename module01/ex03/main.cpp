#include"HumanB.hpp"
#include"HumanA.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        club.setType("AK-47");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
        Weapon HAJRA = Weapon("haJRA MALSSA");;
        HumanB bonawara("Bonawara");
        bonawara.attack();
        club.setType("some other type of club");
        bonawara.attack();
    }
    return 0;
}