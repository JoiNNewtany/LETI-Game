#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "game.hpp"
#include "gameObject/gameObject.hpp"
#include "scene/scene.hpp"
#include "unit/infantry/swordsmanFactory.hpp"

void clearScreen();
Scene* initDefaultScene();

Game::~Game() {
    //TODO: Do memory stuff and stuff
    GameObject::freeAllObjects();
}

void Game::begin() {
    clearScreen();
    scene = initDefaultScene();

    Scene* copytest = new Scene(*scene);

    // Game loop:
    while (true) {
        // Check object limit
        while (GameObject::getObjectCount() > getObjLimit())
            GameObject::freeOldestObject();
        
        // Draw screen
        draw(*scene);
        std::cout << "Copy of the scene:\n";
        draw(*copytest);
    
        // Draw menu
        std::cout << "(h j k l) move\n(ah aj ak al) attack";

        // Capture input
        char test;
        std::cin >> test;
        
        // React to input
        switch (test) {
            case 'h':
                units[0]->moveWest();
                break;
            case 'j':
                units[0]->moveSouth();
                break;
            case 'k':
                units[0]->moveNorth();
                break;
            case 'l':
                units[0]->moveEast();
                break;
            default:
                break;
        }
        
        clearScreen();
    }
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

Scene* Game::initDefaultScene() {
    Scene* scene = new Scene(12);
    
    // Place units, decorations, items
    SwordsmanFactory* sf = new SwordsmanFactory;
    Unit* s = sf->create();
    units.push_back(s);
    s->move(&scene->getCell(2, 2));

    return scene;
}
