#include "knight.hpp"

void Knight::attack(Unit& unit) {
    // Same as horsemen
}

void Knight::evalCondition() {
    // Evaluate this unit's condition after taking damage
}

Knight* Knight::duplicate() {
    Knight* result = new Knight();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
