#ifndef ALLIES_CHECKER_H
#define ALLIES_CHECKER_H

#include "abstract_checker.hpp"
#include "character.hpp"
#include "exceptions.hpp"
#include "constants.hpp"
#include "utils.hpp"
#include <iostream>

class AlliesChecker : public AbstractChecker {
public:
    void performCheck(const Character& playerA, const Character& playerB) override {
        if (areAllies(playerA.getFactions(), playerB.getFactions())) {
            if (nextChecker != nullptr) {
                nextChecker->performCheck(playerA, playerB);
            }
        }
        else {
            throw IllegalActionException(ALLIES_ATTACK);
        }
    }
};

class SelfAttackChecker : public AbstractChecker {
    public:
    void performCheck(const Character& playerA, const Character& playerB) override {
        Character& nonConstRefA = const_cast<Character&>(playerA);
        Character& nonConstRefB = const_cast<Character&>(playerB);
        if (nonConstRefA == nonConstRefB) {
            if (nextChecker != nullptr) {
                nextChecker->performCheck(playerA, playerB);
            }
        }
        else {
            throw IllegalActionException(ALLIES_ATTACK);
        }
    }
};

class PositionChecker : public AbstractChecker {
    public:
    void performCheck(const Character& playerA, const Character& playerB) override {
        // thanks to friendship
        Position playerAPosition = playerA.getPosition();
        Position playerBPosition = playerB.getPosition();

        if (playerBPosition.x > playerAPosition.x + playerA.getRangeMax() ||
            playerBPosition.x < playerAPosition.x - playerA.getRangeMax() ||
            playerBPosition.y > playerAPosition.y + playerA.getRangeMax() ||
            playerBPosition.y < playerAPosition.y - playerA.getRangeMax()) {
                throw IllegalActionException(OUT_OF_RANGE);
            } else {
                if (nextChecker != nullptr) {
                    nextChecker->performCheck(playerA, playerB);
                }
            }
    }
};

class DamageChecker : public AbstractChecker {
    public:
    DamageChecker(int damage) : _damage(damage) {}

    void performCheck(const Character& playerA, const Character& playerB) {
        Character& nonConstRefA = const_cast<Character&>(playerA);
        Character& nonConstRefB = const_cast<Character&>(playerB);
        if (_damage > nonConstRefB.getHealth()) {
            nonConstRefB.setHealth(0);
            nonConstRefB.setAlive(false);
        }
        else if (nonConstRefB.getHealth() - nonConstRefA.getLevel() >= VALID_RANGE) {
            int redDamage = _damage/2;
            nonConstRefB.setHealth(nonConstRefB.getHealth() - redDamage);
        }
        else if (nonConstRefA.getLevel() - nonConstRefB.getLevel() >= VALID_RANGE) {
            int incDamage = 2 * _damage;
            nonConstRefB.setHealth(nonConstRefB.getHealth() - incDamage);
        }
        else {
            nonConstRefB.setHealth(nonConstRefB.getHealth() - _damage);
        }
        if (nextChecker) {
            nextChecker->performCheck(playerA, playerB);
        }
    }
    
    private:
    int _damage;
};

#endif