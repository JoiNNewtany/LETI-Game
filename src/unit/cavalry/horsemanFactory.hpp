#pragma once

#include "unit/unitFactory.hpp"
#include "horseman.hpp"

class HorsemanFactory {
    public:
        Unit* create() { return new Horseman; }
};
