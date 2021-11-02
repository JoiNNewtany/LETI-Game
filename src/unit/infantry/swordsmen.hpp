#pragma once

#include "unit/unit.hpp"

class Swordsmen : public Unit {
    public:
        Swordsmen() : health(250), damage(60), defense(5) {}
        ~Swordsmen() {}

        virtual void attack(Unit&);

    private:
        Cell* currentCell;
        char graphics = 's';
        int health;
        int damage;
        int defense;
};

