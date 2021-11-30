#include "swordsman.hpp"

bool Swordsman::attack(Unit& unit) {
    bool successful = false;

    // If both units are alive
    if (unit.isAlive() && isAlive()) {
        // Deal damage
        unit.setHealth(unit.getHealth() - (damage - unit.getDefense()));
        // Get attacked back because melee combat
        unit.attack(*this);

        successful = true;
    }
    
    return successful;
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
