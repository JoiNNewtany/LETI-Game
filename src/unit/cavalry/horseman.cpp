#include "horseman.hpp"

bool Horseman::attack(Unit& unit) {
    // TODO: Bonus damage against ranged
    bool successful = false;

    // If both units are alive
    if (unit.isAlive() && isAlive()) {
        // Deal damage
        unit.setHealth(unit.getHealth() - (damage - unit.getDefense()));
        
        // Get attacked back because melee combat
        //health = health - (unit.getDamage() - defense);

        successful = true;
    }
    
    return successful; 
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
