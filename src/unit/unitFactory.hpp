#pragma once

#include "unit.hpp"

class UnitFactory {
    public:
        virtual Unit* create() = 0;
        virtual ~UnitFactory();
};

