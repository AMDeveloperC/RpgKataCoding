#ifndef COMBAT_RULES
#define COMBAT_RULES

#include "exceptions.hpp"
#include "constants.hpp"
#include "utils.hpp"
#include "character.hpp"


class CombatRules {
    public:
    CombatRules(const Character&, const Character&);
    CombatRules();
    void dealDamage(int);
    void healDamage(int);
    protected:
    Character _playerA;
    Character _playerB;
};

#endif