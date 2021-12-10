#include "unit.hpp"
#include "cell/cell.hpp"
#include "game/game.hpp"
#include "terrain/terrain.hpp"
#include "item/itemContext.hpp"

Unit::~Unit() {
    currentCell->setUnit(nullptr);
    
    // TODO: Find a better way to remove unit from units vector in Game
    Game& game = Game::instance();
    game.removeUnit(this);
}

bool Unit::move(Cell* cell) {
    bool successful = false;
    
    if (cell != nullptr && cell->getUnit() == nullptr ) {
        Terrain* t = cell->getTerrain();
        bool isPassable = true;
        
        if (t != nullptr)
            isPassable = t->isPassable();

        // Check is the terrain is passable
        if (isPassable) {
            if (currentCell != nullptr) {
                // Remove old terrain effects
                Terrain* oldt = currentCell->getTerrain();
                if (oldt != nullptr)
                    oldt->restore(*this);

                // Clear unit from old cell
                currentCell->setUnit(nullptr);
            }

            // Move unit to new cell
            cell->setUnit(this);
            currentCell = cell;

            // Apply new terrain effects
            if (t != nullptr)
                t->affect(*this);

            // Pick up item if there is one
            Item* i = currentCell->getItem();
            if (i != nullptr) {
                ItemContext* ic = new ItemContext(i);
                
                // Apply item effects
                ic->applyItemEffect(*this);

                // Remove item from cell
                currentCell->setItem(nullptr);
                delete i;

                // Cleanup strategy context
                delete ic;
            }

            successful = true;
        }
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

bool Unit::attackNorth() {
    Unit* u = currentCell->getNorthCell()->getUnit();
    
    if (u != nullptr)
        return attack(*u);

    return false;
}

bool Unit::attackWest() {
    Unit* u = currentCell->getWestCell()->getUnit();
    
    if (u != nullptr)
        return attack(*u);


    return false;
}

bool Unit::attackEast() {
    Unit* u = currentCell->getEastCell()->getUnit();
    
    if (u != nullptr)
        return attack(*u);


    return false;
}

bool Unit::attackSouth() {
    Unit* u = currentCell->getSouthCell()->getUnit();
    
    if (u != nullptr)
        return attack(*u);


    return false;
}
