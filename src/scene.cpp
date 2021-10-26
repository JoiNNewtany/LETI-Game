#include "headers/scene.hpp"
#include <stdexcept>

Scene::Scene(unsigned _rows, unsigned _cols) {
    if (_rows < 1 || _rows > 64) {
        throw std::length_error("_rows");
    }
    if (_cols < 1 || _cols > 64) {
        throw std::length_error("_rows");
    }

    grid.resize(_rows);

    for (unsigned i = 0; i < grid.size(); i++) {
        grid[i].resize(_cols, new Cell());
    }

    rows = _rows;
    cols = _cols;
}

Scene::~Scene() {
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            delete grid[i][j];
        }
    }
}
