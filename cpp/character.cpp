#include "character.hpp"
#include "exceptions.hpp"
#include "constants.hpp"
#include "utils.hpp"
#include <iostream>

int Character::_id = 0;

Character::Character(const Position& p) : _health(1000), _level(1), _isAlive(true) {
    ++_id;
    _pos = new Position(); // never forget to allocate when using pointers!
    _pos->x = p.x;
    _pos->y = p.y;
}

Character::Character() {}

Character::~Character() {
    delete _pos;
    --_id;
}

// copy constructor
Character::Character(const Character& character) : _health(character.getHealth()), _level(character.getLevel()), _isAlive(character.isAlive()) {
    _pos = new Position();
    *_pos = character.getPosition();
}

void Character::setAlive(bool alive) { _isAlive = alive; }

void Character::setHealth(int health) { _health = health; }

void Character::setLevel(int level) { _level = level; }

void Character::addFaction(int faction) { _factions.push_back(faction); }

int Character::getHealth() const { return _health; }

bool Character::isAlive() const { return _isAlive; }

int Character::getLevel() const { return _level; }

std::vector<int> Character::getFactions() const { return _factions; }

std::string Character::getDescription() const { return "A character "; }

void Character::setMaxRange(int range) { _max_range = range; }

int Character::getRangeMax() const { return _max_range; }

Position& Character::getPosition() const { return *_pos; }

bool Character::operator==(const Character& character) { return character._id == this->_id; }