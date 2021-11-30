#pragma once

#include "unit/unitFactory.hpp"
#include "horseman.hpp"

class HorsemanFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Horseman; }
};
