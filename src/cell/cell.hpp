#pragma once

class Unit;

class Cell {
    public:
        Cell(char _graphics = '.') : graphics(_graphics) {}

        ~Cell();

        char getGraphics() const { return graphics; }
        void setGraphics(char c) { graphics = c; }
        
        // HACK: Am I breaking encapsulation by returning
        // these pointers?
        // Probably (most likely) ((yes))

        void setUnit(Unit* u) { unit = u; }
        Unit* getUnit() { return unit; }

        void setNorthCell(Cell* c) { north = c; }
        Cell* getNorthCell() { return north; }

        void setWestCell(Cell* c) { west = c; }
        Cell* getWestCell() { return west; }

        void setEastCell(Cell* c) { east = c; }
        Cell* getEastCell() { return east; }
        
        void setSouthCell(Cell* c) { south = c; }
        Cell* getSouthCell() { return south; }

        // Note that adjacent cells are intentionally not copied
        Cell* duplicate() const;
        Cell* ptr() { return this; }

    private:
        Unit* unit = nullptr;
        //Terrain* terrain = nullptr; // Instead of modifiers?
        //std::vector<CellModifier*> modifiers;
        char graphics;

        // Store pointers to adjacent cells
        Cell* north = nullptr; //up
        Cell* west = nullptr;  //left
        Cell* east = nullptr;  //right
        Cell* south = nullptr; //down
};

