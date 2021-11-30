#pragma once

#include "unit/unit.hpp"

class Spearman : public Unit {
    public:
        Spearman(int hp = 200, int dmg = 80, int df = 3) {
            health = hp;
            damage = dmg;
            defense = df;
            graphics = 'p';
        }
        ~Spearman() {}

        virtual bool attack(Unit&) override;
        virtual Spearman* duplicate() override;
        
        virtual void setHealth(int h) override { health = h; }
        virtual int getHealth() override { return health; }

        virtual void setDefense(int d) override { defense = d; }
        virtual int getDefense() override { return defense; }

        virtual void setDamage(int d) override { damage = d; }
        virtual int getDamage() override { return damage; }

        virtual void setGraphics(char g) override { graphics = g; }
        virtual char getGraphics() override { return graphics; }
};
