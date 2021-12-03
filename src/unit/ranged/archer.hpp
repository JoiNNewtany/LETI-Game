#pragma once

#include "unit/unit.hpp"

class Archer : public Unit {
    public:
        Archer(int hp = 30, int dmg = 8, int df = 2) {
            health = hp;
            damage = dmg;
            defense = df;
            graphics = 'a';
        }
        ~Archer() {}

        virtual bool attack(Unit&) override;
        virtual Archer* duplicate() override;

        virtual void setHealth(int h) override { health = h; }
        virtual int getHealth() override { return health; }

        virtual void setDefense(int d) override { defense = d; }
        virtual int getDefense() override { return defense; }

        virtual void setDamage(int d) override { damage = d; }
        virtual int getDamage() override { return damage; }

        virtual void setGraphics(char g) override { graphics = g; }
        virtual char getGraphics() override { return graphics; }
};
