#pragma once

#include "unit/unitFactory.hpp"
#include "swordsman.hpp"

class SwordsmanFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Swordsman; }
};
