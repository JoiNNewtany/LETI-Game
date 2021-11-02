#pragma once

#include "cell/cell.hpp"
#include <vector>

class Scene {
    using Grid = std::vector<std::vector<Cell*>>;

    public:
	Scene(unsigned _rows, unsigned _cols);
        Scene(unsigned size) : Scene(size, size) {};

        unsigned getRows() const { return rows; }
        unsigned getCols() const { return cols; }
        Cell& getCell(unsigned, unsigned) const;
        const Grid& getGrid() const;

        ~Scene();
    private:
        unsigned getMaxSize() const { return 24; }

        unsigned rows, cols;
	    Grid grid;
};

