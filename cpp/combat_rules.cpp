#include "combat_rules.hpp"
#include "abstract_checker.hpp"
#include "checkers.hpp"

CombatRules::CombatRules(const Character& playerA, const Character& playerB) : _playerA{playerA}, _playerB{playerB} {
}

CombatRules::CombatRules() {}

void CombatRules::dealDamage(int damage) {
    AbstractChecker* alliesChecker = new AlliesChecker();
    AbstractChecker* selfAttackChecker = new SelfAttackChecker();
    AbstractChecker* positionChecker = new PositionChecker();
    AbstractChecker* damageChecker = new DamageChecker(damage);

    // set all next
    alliesChecker->setNextChecker(selfAttackChecker);
    selfAttackChecker->setNextChecker(positionChecker);
    positionChecker->setNextChecker(damageChecker);

    // call the chain
    alliesChecker->performCheck(this->_playerA, this->_playerA);
}

void CombatRules::healDamage(int heal) {
}