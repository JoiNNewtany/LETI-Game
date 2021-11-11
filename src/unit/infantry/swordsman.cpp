#include "swordsman.hpp"

void Swordsman::attack(Unit& unit) {
    // Deal damage
    unit.setHealth(unit.getHealth() - (damage - unit.getDefense()));
    // Get attacked back because melee combat
    unit.attack(*this);
    // Check both units' conditions
    unit.evalCondition();
    evalCondition();

    // TODO: Make classes for infantry etc and let them handle most commands?
}

void Swordsman::evalCondition() {
    // Evaluate this unit's condition after taking damage
}

Swordsman* Swordsman::duplicate() {
    Swordsman* result = new Swordsman();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
