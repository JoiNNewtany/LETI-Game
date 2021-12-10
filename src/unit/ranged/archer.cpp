#include "archer.hpp"

bool Archer::attack(Unit& unit) {
    // Ranged unit thus doesn't take return damage after attacking
    bool successful = false;

    // If both units are alive
    if (unit.isAlive() && isAlive()) {
        // Deal damage
        unit.setHealth(unit.getHealth() - (damage - unit.getDefense()));

        successful = true;
    }
    
    return successful;
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
