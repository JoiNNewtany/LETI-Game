#pragma once

#include "unit/unit.hpp"

class Crossbowman : public Unit {
    public:
        Crossbowman(int hp = 35, int dmg = 12, int df = 2) {
            health = hp;
            damage = dmg;
            defense = df;
            graphics = 'c';
        }
        ~Crossbowman() {}

        virtual bool attack(Unit&) override;
        virtual Crossbowman* duplicate() override;

        virtual void setHealth(int h) override { health = h; }
        virtual int getHealth() override { return health; }

        virtual void setDefense(int d) override { defense = d; }
        virtual int getDefense() override { return defense; }

        virtual void setDamage(int d) override { damage = d; }
        virtual int getDamage() override { return damage; }

        virtual void setGraphics(char g) override { graphics = g; }
        virtual char getGraphics() override { return graphics; }
};
