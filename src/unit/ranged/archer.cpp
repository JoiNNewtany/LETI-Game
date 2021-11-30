#include "archer.hpp"

bool Archer::attack(Unit& unit) {
    // Ranged unit thus doesn't take return damage after attacking
    return false;
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
