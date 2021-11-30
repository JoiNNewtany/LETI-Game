#pragma once

#include "unit/unit.hpp"

class Swordsman : public Unit {
    public:
        Swordsman(int hp = 250, int dmg = 60, int df = 5) {
            health = hp;
            damage = dmg;
            defense = df;
            graphics = 's';
        }
        ~Swordsman() {}

        virtual bool attack(Unit&) override;
        virtual Swordsman* duplicate() override;

        virtual void setHealth(int h) override { health = h; }
        virtual int getHealth() override { return health; }

        virtual void setDefense(int d) override { defense = d; }
        virtual int getDefense() override { return defense; }

        virtual void setDamage(int d) override { damage = d; }
        virtual int getDamage() override { return damage; }

        virtual void setGraphics(char g) override { graphics = g; }
        virtual char getGraphics() override { return graphics; }
};

