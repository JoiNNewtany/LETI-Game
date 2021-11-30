#include "knight.hpp"

bool Knight::attack(Unit& unit) {
    // Same as horsemen
    return false;
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
