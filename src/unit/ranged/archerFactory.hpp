#pragma once

#include "unit/unitFactory.hpp"
#include "archer.hpp"

class ArcherFactory {
    public:
        Unit* create() { return new Archer; }
};
