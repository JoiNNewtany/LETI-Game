#pragma once

#include "unit/unitFactory.hpp"
#include "crossbowman.hpp"

class CrossbowmanFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Crossbowman; }
};
