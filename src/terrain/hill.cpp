#include "hill.hpp"
#include "unit/unit.hpp"

void Hill::affect(Unit& u) {
    u.setDamage(u.getDamage() + 5);
}

void Hill::restore(Unit& u) {
    u.setDamage(u.getDamage() - 5);
}
