#pragma once

#include "item.hpp"

class Unit;

class MedicalSupplies : public Item {
    public:
        MedicalSupplies(unsigned q = 20) {
            quality = q;
            graphics = '+';
        }
        ~MedicalSupplies() {}

        virtual void apply(Unit&) override;

    private:
        unsigned quality;
};
