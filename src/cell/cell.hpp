#pragma once

#include <vector>
#include "gameObject/gameObject.hpp"
#include "unit/unit.hpp"

class Unit;

class Cell {
    public:
        Cell(char _graphics = '.') : graphics(_graphics) {}
        //Cell(std::vector<GameObject*> _content, char _graphics = '.')
            //: content(_content), graphics(_graphics) {}
        
        char getGraphics() const { return graphics; }
        void setGraphics(char c) { graphics = c; }
        
        // HACK: Am I breaking encapsulation by returning these pointers?
        // Probably (most likely) ((yes))

        void setUnit(Unit* u) { unit = u; }
        Unit* getUnit() const { return unit; }

        void setNorthCell(Cell* c) { north = c; }
        Cell* getNorthCell() const { return north; }

        void setWestCell(Cell* c) { west = c; }
        Cell* getWestCell() const { return west; }

        void setEastCell(Cell* c) { east = c; }
        Cell* getEastCell() const { return east; }
        
        void setSouthCell(Cell* c) { south = c; }
        Cell* getSouthCell() const { return south; }

        Cell* ptr() { return this; }

        ~Cell();

    private:
        Unit* unit = nullptr;
        //std::vector<CellModifier*> modifiers;
        char graphics; // Gets overwritten by content unless empty

        // Store pointers to adjacent cells
        Cell* north = nullptr; //up
        Cell* west = nullptr;  //left
        Cell* east = nullptr;  //right
        Cell* south = nullptr; //down
};

