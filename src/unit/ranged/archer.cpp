#include "archer.hpp"

void Archer::attack(Unit& unit) {
    // Ranged unit thus doesn't take return damage after attacking
}

void Archer::evalCondition() {
    // Evaluate this unit's condition after taking damage
}

Archer* Archer::duplicate() {
    Archer* result = new Archer();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
