#include "river.hpp"
#include "unit/unit.hpp"

void River::affect(Unit& u) {
    u.setDefense(u.getDefense() - 5);
}

void River::restore(Unit& u) {
    u.setDefense(u.getDefense() + 5);
}
