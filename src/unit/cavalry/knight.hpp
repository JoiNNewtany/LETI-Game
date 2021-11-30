#pragma once

#include "unit/unit.hpp"

class Knight : public Unit {
    public:
        Knight(int hp = 280, int dmg = 80, int df = 25) {
            health = hp;
            damage = dmg;
            defense = df;
            graphics = 'k';
        }
        ~Knight() {}

        virtual bool attack(Unit&) override;
        virtual Knight* duplicate() override;

        virtual void setHealth(int h) override { health = h; }
        virtual int getHealth() override { return health; }

        virtual void setDefense(int d) override { defense = d; }
        virtual int getDefense() override { return defense; }

        virtual void setDamage(int d) override { damage = d; }
        virtual int getDamage() override { return damage; }

        virtual void setGraphics(char g) override { graphics = g; }
        virtual char getGraphics() override { return graphics; }
};
