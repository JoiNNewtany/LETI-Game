#pragma once

#include "gameObject/gameObject.hpp"

class Unit;

class Item : public GameObject {
    public:
        virtual ~Item() {}

        virtual void apply(Unit&) = 0;
};
