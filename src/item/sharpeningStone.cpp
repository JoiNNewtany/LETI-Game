#include "sharpeningStone.hpp"
#include "unit/unit.hpp"

// Permanently increase damage
void SharpeningStone::apply(Unit& unit) {
    unit.setDamage(unit.getDamage() + quality);
}
