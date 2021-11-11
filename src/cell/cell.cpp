#include "cell.hpp"

Cell* Cell::duplicate() const {
    Cell* result = new Cell();

    if (unit != nullptr) {
        // Copy unit and move to new cell
        unit->duplicate()->move(result);
    }

    // TODO: Copy modifiers

    result->graphics = graphics;

    return result;
}

Cell::~Cell() {
    //TODO: Destruct units and modifiers vector
}

