#pragma once

#include "unit/unitFactory.hpp"
#include "swordsman.hpp"

class SwordsmanFactory {
    public:
        Unit* create() { return new Swordsman; }
};
