#pragma once

#include "gameObject/gameObject.hpp"
#include "cell/cell.hpp"

class Cell;

class Unit : GameObject {
    public:
        virtual ~Unit() {}

        virtual void setHealth(int h) { health = h; }
        virtual int getHealth() { return health; }

        virtual void setDefense(int d) { defense = d; }
        virtual int getDefense() { return defense; }

        virtual void setDamage(int d) { damage = d; }
        virtual int getDamage() { return damage; }

        virtual void setGraphics(char g) { graphics = g; }
        virtual char getGraphics() { return graphics; }

        virtual void attack(Unit&) = 0;
        virtual void evalCondition() = 0;
        virtual Unit* duplicate() = 0;
        virtual bool move(Cell*);
        virtual bool moveNorth();
        virtual bool moveWest();
        virtual bool moveEast();
        virtual bool moveSouth();

    protected:
        // Cell that the unit is currently in
        Cell* currentCell;
        char graphics;
        int health;
        int damage;
        // Gets subtracted from damage
        int defense;
};

