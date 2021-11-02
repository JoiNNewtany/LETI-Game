#pragma once

#include <vector>
#include "gameObject/gameObject.hpp"
#include "scene/scene.hpp"

enum GameState {
    P1_TURN,
    P2_TURN,
    GAME_OVER,
    MENU,
};

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
        unsigned getObjLimit() { return 64; }

        Scene* scene;
};
