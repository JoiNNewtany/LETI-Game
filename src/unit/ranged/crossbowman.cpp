#include "crossbowman.hpp"

bool Crossbowman::attack(Unit& unit) {
    // Same as Archers
    bool successful = false;

    // If both units are alive
    if (unit.isAlive() && isAlive()) {
        // Deal damage
        unit.setHealth(unit.getHealth() - (damage - unit.getDefense()));

        successful = true;
    }
    
    return successful; 
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
