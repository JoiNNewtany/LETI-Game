#pragma once

#include "terrain.hpp"

class Unit;

// Lowers Unit's defence
class River : public Terrain {
    public:
        River() {
            passable = true;
            graphics = '~';
        }
        ~River() {}

        virtual void affect(Unit&) override;
        virtual void restore(Unit&) override;
};
