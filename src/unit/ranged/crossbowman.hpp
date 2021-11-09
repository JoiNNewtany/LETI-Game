#pragma once

#include "unit/unit.hpp"

class Crossbowman : public Unit {
    public:
        Crossbowman() : health(150), damage(70), defense(1) {}
        ~Crossbowman() {}

        virtual void attack(Unit&);

        virtual void setHealth(int h) { health = h; }
        virtual int getHealth() { return health; }

        virtual void setDefense(int d) { defense = d; }
        virtual int getDefense() { return defense; }

        virtual void setDamage(int d) { damage = d; }
        virtual int getDamage() { return damage; }

        virtual void setGraphics(char g) { graphics = g; }
        virtual char getGraphics() { return graphics; }

    private:
        Cell* currentCell;
        char graphics = 'c';
        int health;
        int damage;
        int defense;
};
