#ifndef DECORATOR_CHARACTER
#define DECORATOR_CHARACTER

#include "character.hpp"

class DecoratorCharacter : public Character {
    public:
    DecoratorCharacter(Character* character);
    private:
    Character* _character;
};

DecoratorCharacter::DecoratorCharacter(Character* character) : _character(character) {}

#endif