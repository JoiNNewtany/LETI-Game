#include "unit.hpp"

bool Unit::move(Cell* cell) {
    bool successful = false;
    
    if (cell != nullptr && cell->getUnit() == nullptr ) {
        if (currentCell != nullptr)
            currentCell->setUnit(nullptr);
        cell->setUnit(this);
        currentCell = cell->ptr();
        successful = true;
    }

    return successful;
}

bool Unit::moveNorth() {
    return move(currentCell->getNorthCell());
}

bool Unit::moveWest() {
    return move(currentCell->getWestCell());
}

bool Unit::moveEast() {
    return move(currentCell->getEastCell());
}

bool Unit::moveSouth() {
    return move(currentCell->getSouthCell());
}
