#pragma once

#include "item.hpp"

class Unit;

class SharpeningStone : public Item {
    public:
        SharpeningStone(unsigned q = 5) {
            quality = q;
            graphics = '7';
        }
        ~SharpeningStone() {}

        virtual void apply(Unit&) override;

    private:
        unsigned quality;
};
