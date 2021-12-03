#pragma once

#include <vector>
#include "unit/unit.hpp"
#include "observer/iListener.hpp"

class UnitFactory;

class Town : public Unit, public IListener {
    public:
        Town(unsigned mu = 8, int hp = 200, int df = 5) {
            maxUnits = mu;
            health = hp;
            defense = df;
            graphics = '@';
        }
        ~Town() {}

        virtual bool attack(Unit&) override { return false; }
        virtual Town* duplicate() override;

        Unit* produce(const UnitFactory&);
        bool canProduce() const { return ownedUnits < maxUnits; }
        // Returns a free adjacent cell for unit placement
        // if there is one. Don't forget to null check!
        Cell* getPlacementCell() const;

        // Implements IListener
        virtual void update() override { ownedUnits--; }

        void setOwnedUnits(unsigned u) { ownedUnits = u; }
        unsigned getOwnedUnits() { return ownedUnits; }

        void setMaxUnits(unsigned u) { maxUnits = u; }
        unsigned getMaxUnits() { return maxUnits; }

        virtual void setHealth(int h) override { health = h; }
        virtual int getHealth() override { return health; }

        virtual void setDefense(int d) override { defense = d; }
        virtual int getDefense() override { return defense; }

        virtual void setDamage(int d) override { damage = d; }
        virtual int getDamage() override { return damage; }

        virtual void setGraphics(char g) override { graphics = g; }
        virtual char getGraphics() override { return graphics; }

    protected:
        unsigned ownedUnits = 0;
        unsigned maxUnits;
};

