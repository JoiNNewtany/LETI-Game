#include "crossbowman.hpp"

bool Crossbowman::attack(Unit& unit) {
    // Same as Archers
    return false;
}

Crossbowman* Crossbowman::duplicate() {
    Crossbowman* result = new Crossbowman();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
