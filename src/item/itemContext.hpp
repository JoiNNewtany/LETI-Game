#pragma once

#include "item.hpp"

class Unit;

class ItemContext {
    public:
        ItemContext(Item* i) : item(i) {}
        ~ItemContext() {}

        void setItem(Item* i) { item = i; }
        void applyItemEffect(Unit& u) { item->apply(u); }

    private:
        Item* item;
};
