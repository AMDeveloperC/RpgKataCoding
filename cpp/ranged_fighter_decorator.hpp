#ifndef RANGED_FIGHTER_H
#define RANGED_FIGHTER_H

#include "decorator_character.hpp"
#include "constants.hpp"
#include <iostream>
#include <string>

class RangedFighterDecorator : public DecoratorCharacter {
    public:
    RangedFighterDecorator(Character* character);
    std::string getDescription() const override;
};

RangedFighterDecorator::RangedFighterDecorator(Character* character) : DecoratorCharacter(character) {
    DecoratorCharacter::setMaxRange(MAX_RANGE_RANGED);
}

std::string RangedFighterDecorator::getDescription() const {
    std::string ans = "This is a melee fighters with " + std::to_string(DecoratorCharacter::getRangeMax());
    return ans;
}

#endif