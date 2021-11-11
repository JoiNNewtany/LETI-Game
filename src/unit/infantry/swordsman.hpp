#pragma once

#include "unit/unit.hpp"

class Swordsman : public Unit {
    public:
        Swordsman() : health(250), damage(60), defense(5) {}
        ~Swordsman() {}

        virtual void attack(Unit&);
        virtual void evalCondition();
        virtual Swordsman* duplicate();

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

