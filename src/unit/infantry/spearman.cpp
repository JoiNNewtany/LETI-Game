#include "spearman.hpp"

void Spearman::attack(Unit& unit) {
    // Deal additional damage to cavalry
}

void Spearman::evalCondition() {
    // Evaluate this unit's condition after taking damage
}

Spearman* Spearman::duplicate() {
    Spearman* result = new Spearman();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
