#pragma once

#include <vector>

class Scene;
class Unit;
class Town;

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

        // Temporary members -- REMOVE LATER
        void removeUnit(Unit*);

    private:
        Game() {}
        ~Game();

        void end();
        void draw(const Scene&) const;
        void checkObjects();
        Scene* initDefaultScene();
        unsigned getObjectLimit() { return objectLimit; }

        unsigned objectLimit = 32;
        Scene* scene;
        // TODO: Create Player class
        // std::vector<Player> players;
        
        // Temporary fields -- REMOVE LATER
        std::vector<Unit*> units;
        Town* town;
};
