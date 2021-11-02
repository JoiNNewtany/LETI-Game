#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "game.hpp"
#include "gameObject/gameObject.hpp"
#include "scene/scene.hpp"
#include "unit/infantry/swordsmen.hpp"

void clearScreen();
Scene* initDefaultScene();

Game::~Game() {
    //TODO: Do memory stuff and stuff
}

void Game::begin() {
    clearScreen();
    scene = initDefaultScene();

    // Game loop:
    // while (true) ...
    // Check object limit
    while (GameObject::getObjectCount() > getObjLimit()) {
        GameObject::freeOldestObject();
    }
    // Draw screen
    draw(*scene);
    
    // Draw menu

    // Capture input
    
    //clearScreen();
}

void Game::end() {
    //
}

void Game::draw(const Scene& scn) const {
    auto grid = scn.getGrid();

    std::cout << std::endl;
    
    for (auto cells : grid) {
        for (Cell* cell : cells) {
            if (cell->getUnit() != nullptr)
                std::cout << cell->getUnit()->getGraphics() << ' ';
            // else if (cell->getModifier() != nullptr)
            //     std::cout << cell->getModifier()->getGraphics() << ' ';
            else
                std::cout << cell->getGraphics() << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void clearScreen() {
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

Scene* initDefaultScene() {
    Scene* scene = new Scene(12);
    
    // Place units, decorations, items
    Swordsmen* s = new Swordsmen();
    scene->getCell(2, 2).setUnit(s);
    s->moveSouth();

    return scene;
}
