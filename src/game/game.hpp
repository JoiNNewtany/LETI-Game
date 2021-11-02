#pragma once

#include <vector>
#include "gameObject/gameObject.hpp"
#include "scene/scene.hpp"

// Handles game logic
class Game {
    public:
        // Implements Meyers' Singleton
        static Game& instance()
        {
            static Game g;
            return g;
        }

        void begin();

    private:
        Game() {}
        ~Game();

        void end();
        void draw(const Scene&) const;
        void checkObjects();
        Scene* initDefaultScene();
        unsigned getObjLimit() { return 64; }

        Scene* scene;
        // TODO: Create player class/struct???
        // std::vector<Player> players;
        std::vector<Unit*> units;
};
