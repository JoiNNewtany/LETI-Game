#pragma once

#include "unit/unit.hpp"

class Archer : public Unit {
    public:
        Archer() : health(200), damage(50), defense(1) {}
        ~Archer() {}

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
        char graphics = 'a';
        int health;
        int damage;
        int defense;
};
