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
