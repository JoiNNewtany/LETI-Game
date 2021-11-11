#pragma once

#include "unit/unit.hpp"

class Knight : public Unit {
    public:
        Knight() : health(280), damage(80), defense(25) {}
        ~Knight() {}

        virtual void attack(Unit&);
        virtual void evalCondition();
        virtual Knight* duplicate();

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
        char graphics = 'k';
        int health;
        int damage;
        int defense;
};
