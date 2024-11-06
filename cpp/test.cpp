#include <iostream>
#include "utils.hpp"
#include "character.hpp"
#include "exceptions.hpp"
#include "constants.hpp"
#include "combat_rules.hpp"
#include "melee_fighters_decorator.hpp"
#include "ranged_fighter_decorator.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(Character, theyShouldBeDistinct) {
    Character* c1 = new Character({0,0});
    Character* c2 = new Character({1,1});
    ASSERT_FALSE(c1 == c2);
}

TEST(UtilsTest, shouldBeAllies) {
    std::vector<int> origin = {1, 4, 7, 9};
    std::vector<int> modified = {2, 4, 8};
    bool outcome = areAllies(origin, modified);
    EXPECT_TRUE(outcome);
}

TEST(UtilsTest, shouldNotBeAllies) {
    std::vector<int> origin = {1, 4, 7, 9};
    std::vector<int> modified = {2, 5, 8};
    bool outcome = areAllies(origin, modified);
    EXPECT_FALSE(outcome);
}

TEST(UtilsTest, shouldReturnTrue) {
    std::vector<int> origin = {};
    std::vector<int> modified = {};
    bool outcome = areAllies(origin, modified);
    EXPECT_TRUE(outcome);
}

TEST(CombatTest, shouldNotFail) {
    Character* c1 = new Character({0,0});
    Character* c2 = new Character({1,1});
    CombatRules* combat = new CombatRules(*c1, *c2);
    combat->dealDamage(7);
}

/*TEST(CharacterTest, shouldHealADamage) {
    Character* c1 = new Character({0,0});
    Character* c2 = new Character({1,1});
    try {
        c1->dealDamageToCharacter(*c1, 20);
        FAIL() << "Expected IllegalActionException";
    }
    catch(IllegalActionException const & err) {
        EXPECT_EQ(err.what(), std::string(SELF_DEAL_ERROR));
    }
    catch(...) {
        FAIL() << "Expected IllegalActionException";
    }
}*/

TEST(CharacterTest, shouldCreateAMeleeRange) {
    Character* c1 = new Character({1,2});
    c1 = dynamic_cast<MeleeFighterDecorator*>(new MeleeFighterDecorator(c1));
    EXPECT_EQ(c1->getDescription(), "This is a melee fighters with 2");
}

TEST(CharacterTest, shouldCreateARangedFigter) {
    Character* c1 = new Character({3,4});
    c1 = dynamic_cast<RangedFighterDecorator*>(new RangedFighterDecorator(c1));
    EXPECT_EQ(c1->getDescription(), "This is a melee fighters with 20");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}