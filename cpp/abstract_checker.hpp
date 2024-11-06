#ifndef ABSTRACT_CHECKER
#define ABSTRACT_CHECKER

#include "character.hpp"
#include <memory>

class AbstractChecker {
protected:
    std::unique_ptr<AbstractChecker> nextChecker;

public:
    AbstractChecker() : nextChecker(nullptr) {}

    void setNextChecker(AbstractChecker *next) {
        nextChecker.reset(next);
    }

    virtual void performCheck(const Character&, const Character&) = 0;
};

#endif