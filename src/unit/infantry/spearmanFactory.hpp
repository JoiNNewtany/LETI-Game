#pragma once

#include "unit/unitFactory.hpp"
#include "spearman.hpp"

class SpearmanFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Spearman; }
};
