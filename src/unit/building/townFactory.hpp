#pragma once

#include "unit/unitFactory.hpp"
#include "town.hpp"

class TownFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Town; }
};
