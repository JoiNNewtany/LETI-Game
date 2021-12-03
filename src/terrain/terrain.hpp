#pragma once

#include "gameObject/gameObject.hpp"

class Unit;

class Terrain : public GameObject {
    public:
        Terrain() {}
        virtual ~Terrain() {}
        virtual void affect(Unit&) = 0;
        virtual void restore(Unit&) = 0;
        virtual bool isPassable() { return passable; }

    protected:
        bool passable;
};
