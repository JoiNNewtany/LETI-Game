#pragma once

#include "terrain.hpp"

class Unit;

// Deals damage on a unit
class Spike : public Terrain {
    public:
        Spike() {
            passable = true;
            graphics = '!';
        }
        ~Spike() {}

        virtual void affect(Unit&) override;
        virtual void restore(Unit&) override;
};
