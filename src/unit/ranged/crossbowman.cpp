#include "crossbowman.hpp"

void Crossbowman::attack(Unit& unit) {
    // Same as Archers
}

void Crossbowman::evalCondition() {
    // Evaluate this unit's condition after taking damage
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
