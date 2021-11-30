#pragma once

#include "unit/unitFactory.hpp"
#include "archer.hpp"

class ArcherFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Archer; }
};
