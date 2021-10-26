#pragma once

#include <vector>
#include "gameObject.hpp"

class Cell {
    public:
        Cell(std::vector<GameObject*> _content, char _graphics = '.')
            : content(_content), graphics(_graphics) {}
        ~Cell();

    private:
        std::vector<GameObject*> content;
        char graphics; // Gets overwritten by content unless empty
};

