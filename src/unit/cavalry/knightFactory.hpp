#pragma once

#include "unit/unitFactory.hpp"
#include "knight.hpp"

class KnightFactory : public UnitFactory {
    public:
        Unit* create() const override { return new Knight; }
};
