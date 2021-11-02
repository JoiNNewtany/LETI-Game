#include "scene.hpp"
#include <stdexcept>

Scene::Scene(unsigned _rows, unsigned _cols) {
    if (_rows < 1 || _rows > getMaxSize()) {
        throw std::length_error("_rows");
    }
    if (_cols < 1 || _cols > getMaxSize()) {
        throw std::length_error("_rows");
    }

    // Initialize grid
    grid.resize(_rows);

    for (unsigned i = 0; i < grid.size(); i++) {
        grid[i].resize(_cols);
    }

    rows = _rows;
    cols = _cols;

    // Create new cells
    for (unsigned i = 0; i < _rows; i++) {
        for (unsigned j = 0; j < _cols; j++) {
            grid[i][j] = new Cell();
        }
    }

    // Connect adjacent cells together
    for (unsigned i = 0; i < _rows; i++) {
        for (unsigned j = 0; j < _cols; j++) {
            if (i != 0)
                // Connect cell above
                grid[i][j]->setNorthCell(grid[i - 1][j]);
            if (i != _rows - 1)
                // Connect cell below
                grid[i][j]->setSouthCell(grid[i + 1][j]);
            if (j != 0)
                // Connect cell to the left
                grid[i][j]->setWestCell(grid[i][j - 1]);
            if (j != _cols - 1)
                // Connect cell to the right
                grid[i][j]->setEastCell(grid[i][j + 1]);
        }
    }
}

Scene::~Scene() {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            delete grid[i][j];
        }
    }
}

const Scene::Grid& Scene::getGrid() const {
    const Scene::Grid& ref = grid;
    return ref;
}

Cell& Scene::getCell(unsigned row, unsigned col) const {
    //TODO: Arg checks!
    return *grid[row][col];
}
