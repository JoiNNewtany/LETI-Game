#include "knight.hpp"

bool Knight::attack(Unit& unit) {
    // TODO: Bonus damage against ranged units
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

Knight* Knight::duplicate() {
    Knight* result = new Knight();

    // CurrentCell is not copied in order not to break the game grid

    result->graphics = graphics;
    result->health = health;
    result->damage = damage;
    result->defense = defense;

    return result;
}
