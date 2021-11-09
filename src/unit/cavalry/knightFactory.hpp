#pragma once

#include "unit/unitFactory.hpp"
#include "knight.hpp"

class KnightFactory {
    public:
        Unit* create() { return new Knight; }
};
