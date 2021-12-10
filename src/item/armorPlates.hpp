#pragma once

#include "item.hpp"

class Unit;

class ArmorPlates : public Item {
    public:
        ArmorPlates(unsigned q = 3) {
            quality = q;
            graphics = ']';
        }
        ~ArmorPlates() {}

        virtual void apply(Unit&) override;

    private:
        unsigned quality;
};
