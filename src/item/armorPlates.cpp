#include "armorPlates.hpp"
#include "unit/unit.hpp"

// Permanently increase defense
void ArmorPlates::apply(Unit& unit) {
    unit.setDefense(unit.getDefense() + quality);
}
