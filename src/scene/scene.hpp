#pragma once

#include "cell/cell.hpp"
#include <vector>

class Scene {
    public:
	Scene(unsigned _rows, unsigned _cols);
        Scene(unsigned size) : Scene(size, size) {};

        unsigned getRows() { return rows; }
        unsigned getCols() { return cols; }

        ~Scene();
    private:
        unsigned rows, cols;
	std::vector<std::vector<Cell*>> grid;
};
