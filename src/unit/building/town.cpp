#include "town.hpp"
#include "cell/cell.hpp"
#include "unit/unitFactory.hpp"

Town* Town::duplicate() {
    Town* result = new Town();

    result->graphics = graphics;
    result->ownedUnits = ownedUnits;
    result->maxUnits = maxUnits;
    result->health = health;
    result->defense = defense;

    // TODO: Assign duplicated units to the base that owns them

    return result;
}

Unit* Town::produce(const UnitFactory& factory) {
    if (canProduce() && getPlacementCell() != nullptr) {
        Unit* result = factory.create();
        ownedUnits++;
        result->subscribe(this);
        return result;
    }

    return nullptr;
}

Cell* Town::getPlacementCell() const {
    if (currentCell != nullptr) {
        Cell* cell = currentCell->getSouthCell();

        if (cell != nullptr && cell->getUnit() == nullptr) {
            return cell;
        }

        cell = currentCell->getWestCell();

        if (cell != nullptr && cell->getUnit() == nullptr) {
            return cell;
        }

        cell = currentCell->getEastCell();

        if (cell != nullptr && cell->getUnit() == nullptr) {
            return cell;
        }

        cell = currentCell->getNorthCell();

        if (cell != nullptr && cell->getUnit() == nullptr) {
            return cell;
        }
    }

    return nullptr;
}

