#ifndef MELEE_FIGHTER_H
#define MELEE_FIGHTER_H

#include "decorator_character.hpp"
#include "constants.hpp"
#include <iostream>
#include <string>

class MeleeFighterDecorator : public DecoratorCharacter {
    public:
    MeleeFighterDecorator(Character* character);
    std::string getDescription() const override;
};

MeleeFighterDecorator::MeleeFighterDecorator(Character* character) : DecoratorCharacter(character) {
    DecoratorCharacter::setMaxRange(MAX_RANGE_MELEE); // access to superclass method
}

std::string MeleeFighterDecorator::getDescription() const {
    std::string ans = "This is a melee fighters with " + std::to_string(DecoratorCharacter::getRangeMax());
    return ans;
}

#endif