#pragma once

#include "unit/unit.hpp"

class Horseman : public Unit {
    public:
        Horseman() : health(220), damage(50), defense(2) {}
        ~Horseman() {}

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
        char graphics = 's';
        int health;
        int damage;
        int defense;
};
