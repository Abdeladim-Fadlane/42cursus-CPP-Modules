#include <iostream>
#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string &weaponType) : type(weaponType) {}

    const std::string& getType() const {
        return type;
    }

    void setType(const std::string &newType) {
        type = newType;
    }
};

class HumanA {
private:
    std::string name;
    Weapon weapon;

public:
    HumanA(const std::string &humanName, const Weapon &humanWeapon)
        : name(humanName), weapon(humanWeapon) {}

    void attack() const {
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    }
};

class HumanB {
private:
    std::string name;
    Weapon *weaponPtr;

public:
    HumanB(const std::string &humanName) : name(humanName), weaponPtr(nullptr) {}

    void setWeapon(Weapon *newWeapon) {
        weaponPtr = newWeapon;
    }

    void attack() const {
        if (weaponPtr) {
            std::cout << name << " attacks with their " << weaponPtr->getType() << std::endl;
        } else {
            std::cout << name << " is unarmed and cannot attack." << std::endl;
        }
    }
};

int main() {
    Weapon club("crude spiked club");

    // HumanA example
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    // HumanB example
    HumanB jim("Jim");
    jim.setWeapon(&club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();

    return 0;
}
