#include "medicalSupplies.hpp"
#include "unit/unit.hpp"

// Permanently increase defense
void MedicalSupplies::apply(Unit& unit) {
    int health = unit.getHealth() + quality;
    
    if (health >= unit.getMaxHealth())
        unit.setHealth(unit.getMaxHealth());
    else
        unit.setHealth(health);
}
