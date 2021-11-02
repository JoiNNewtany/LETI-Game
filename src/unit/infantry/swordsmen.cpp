#include "swordsmen.hpp"

void Swordsmen::attack(Unit& unit) {
    // Deal damage
    unit.setHealth(unit.getHealth() - (damage - unit.getDefense()));
    // Get attacked back because melee combat
    unit.attack(*this);
    // Check both units' conditions
    unit.evalCondition();
    evalCondition();
}
