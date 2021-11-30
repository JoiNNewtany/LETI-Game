#pragma once

#include "unit.hpp"

class UnitFactory {
    public:
        virtual Unit* create() const = 0;
        virtual ~UnitFactory() {}
};

