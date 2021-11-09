#pragma once

#include "unit/unitFactory.hpp"
#include "crossbowman.hpp"

class CrossbowmanFactory {
    public:
        Unit* create() { return new Crossbowman; }
};
