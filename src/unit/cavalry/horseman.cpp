#include "horseman.hpp"

void Horseman::attack(Unit& unit) {
    // Bonus damage against ranged
}

void Horseman::evalCondition() {
    // Evaluate this unit's condition after taking damage
}

Horseman* Horseman::duplicate() {
    Horseman* result = new Horseman();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
