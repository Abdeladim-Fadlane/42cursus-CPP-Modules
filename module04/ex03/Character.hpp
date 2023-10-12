#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *tmp;
        AMateria *_inventory[4];
        bool isFull(AMateria** m);
    public:
        Character();
        Character(const Character& obj);
        Character& operator=(const Character &obj);
        Character(const std::string & name);
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx) ;
        void use(int idx, ICharacter& target);    
};
#endif