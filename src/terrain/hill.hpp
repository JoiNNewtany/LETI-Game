#pragma once

#include "terrain.hpp"

class Unit;

// Lowers Unit's defence
class Hill : public Terrain {
    public:
        Hill() {
            passable = true;
            graphics = '-';
        }
        ~Hill() {}

        virtual void affect(Unit&) override;
        virtual void restore(Unit&) override;

    private:
        
};
