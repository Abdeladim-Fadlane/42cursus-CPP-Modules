#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include"ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria *_inventory[4];
        std::string _name;
        bool isFull(AMateria** m);
        AMateria *tmp[4];
        int *ptr; 
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