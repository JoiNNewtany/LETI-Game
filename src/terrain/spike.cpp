#include "spike.hpp"
#include "unit/unit.hpp"

void Spike::affect(Unit& u) {
    u.setHealth(u.getHealth() - 5);
}

void Spike::restore(Unit&) { }
