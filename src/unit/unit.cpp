#include "unit.hpp"
#include "cell/cell.hpp"
#include "game/game.hpp"

Unit::~Unit() {
    currentCell->setUnit(nullptr);
    
    // HACK: Find a better way to remove unit from units vector in Game
    Game& game = Game::instance();
    game.removeUnit(this);
}

bool Unit::move(Cell* cell) {
    bool successful = false;
    
    if (cell != nullptr && cell->getUnit() == nullptr ) {
        if (currentCell != nullptr)
            currentCell->setUnit(nullptr);
        cell->setUnit(this);
        currentCell = cell;
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
