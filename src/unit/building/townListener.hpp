#pragma once

#include "observer/iListener.hpp"
#include "town.hpp"

class DestructionTownListener : public IListener {
    public:
        DestructionTownListener(Town& t) : town(t) {}
        ~DestructionTownListener() {}

        virtual void update() override {
            town.decOwnedUnits();
        }

    private:
        Town& town;
};
