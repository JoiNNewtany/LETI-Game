#pragma once

#include "terrain.hpp"

class Unit;

// Lowers Unit's defence
class Mountain : public Terrain {
    public:
        Mountain() {
            passable = false;
            graphics = '^';
        }
        ~Mountain() {}

        virtual void affect(Unit&) override;
        virtual void restore(Unit&) override;
};
