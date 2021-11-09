#pragma once

#include "unit/unit.hpp"

class Spearman : public Unit {
    public:
        Spearman() : health(200), damage(80), defense(3) {}
        ~Spearman() {}

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
        char graphics = 'p';
        int health;
        int damage;
        int defense;
};
