pragma once

#include "unit/unitFactory.hpp"
#include "spearman.hpp"

class SpearmanFactory {
    public:
        Unit* create() { return new Spearman; }
};
