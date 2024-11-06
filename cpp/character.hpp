#ifndef CHARACTER_H
#define CHARACTER_H

#include "position.hpp"
#include <string>
#include <memory>
#include <vector>

class PositionChecker;

class Character {
    public:
    Character();
    Character(const Position&);
    ~Character();

    // copy constructor
    Character(const Character&);

    void setHealth(int);
    void setAlive(bool);
    void setLevel(int);
    void addFaction(int);

    int getHealth() const;
    bool isAlive() const;
    int getLevel() const;
    std::vector<int> getFactions() const;

    bool operator==(const Character&);

    virtual std::string getDescription() const;

    friend class PositionChecker;
    
    protected:
    void setMaxRange(int);
    int getRangeMax() const;
    Position& getPosition() const;
    int _max_range;
    std::vector<int> _factions;

    private:
    int _health;
    int _level;
    bool _isAlive;
    static int _id;
    Position* _pos;
};

#endif
