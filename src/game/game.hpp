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
        Game();
        //Game(Scene);

        void begin();
        void end();

        ~Game();
    private:
        void draw(const Scene& scene);

        // Stores all objects created in the game for easy memory management
        std::vector<GameObject*> globalObjects;
};
