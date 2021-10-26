#pragma once

#include <vector>
#include "gameObject/gameObject.hpp"

class Cell {
    public:
        Cell(char _graphics = '.') : graphics(_graphics) {}
        //Cell(std::vector<GameObject*> _content, char _graphics = '.')
            //: content(_content), graphics(_graphics) {}
        ~Cell();

    private:
        //std::vector<Unit*> units;
        //std::vector<CellModifier*> modifiers;
        char graphics; // Gets overwritten by content unless empty
};

