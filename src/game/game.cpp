#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "game.hpp"
#include "gameObject/gameObject.hpp"
#include "scene/scene.hpp"
#include "unit/infantry/swordsmanFactory.hpp"
#include "unit/building/town.hpp"
#include "unit/unitFactory.hpp"

void clearScreen();
Scene* initDefaultScene();

Game::~Game() {
    // TODO: Do memory stuff and stuff
    GameObject::freeAllObjects();
}

void Game::begin() {
    clearScreen();
    scene = initDefaultScene();

    // TODO: DELETE AFTER TESTING
    /*
    Town* t = new Town();
    t->move(&scene->getCell(6, 9));
    SwordsmanFactory* sf = new SwordsmanFactory();
    
    Unit* u1 = t->produce(*sf);
    if (u1 != nullptr) {
        units.push_back(u1);
        u1->move(t->getPlacementCell());
    }

    Unit* u2 = t->produce(*sf);
    if (u2 != nullptr) {
        units.push_back(u2);
        u2->move(t->getPlacementCell());
    }
    
    delete u2;
    */
    SwordsmanFactory* sf = new SwordsmanFactory();

    // Game loop:
    while (true) {
        // Check object limit
        while (GameObject::getObjectCount() > getObjectLimit())
            GameObject::freeOldestObject();

        // Draw screen
        draw(*scene);
    
        // Draw menu
        std::cout << "Objects: " << GameObject::getObjectCount() << '/'
                  << getObjectLimit() << '\n';

        std::cout << "Town units: " << town->getOwnedUnits() << '\n';

        for (size_t i = 0; i < units.size(); i++) {
            std::cout << i << ": " << units[i]->getGraphics() << std::endl;
        }

        std::cout << "\nCommand syntax: <command><unit_number>\n";
        std::cout << "(h j k l) move\n(u) make unit\n(d) delete unit\n";

        // Capture input
        char command;
        unsigned selection;

        std::cin >> command >> selection;
        // if end of cin, do switch, else input selection
        
        // React to input
        switch (command) {
            case 'h':
                units[selection]->moveWest();
                break;
            case 'j':
                units[selection]->moveSouth();
                break;
            case 'k':
                units[selection]->moveNorth();
                break;
            case 'l':
                units[selection]->moveEast();
                break;
            case 'u':
                {
                    Unit* u = town->produce(*sf);
                    if (u != nullptr) {
                        units.push_back(u);
                        u->move(town->getPlacementCell());
                    }
                    break;
                }
            case 'd':
                {
                    delete units[selection];
                    break;
                }
            default:
                break;
        }
        
        clearScreen();
    }
}

void Game::end() {
    // TODO: end the game
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

    town = new Town();
    town->move(&scene->getCell(6, 9));

    SwordsmanFactory* sf = new SwordsmanFactory();
    
    Unit* u = town->produce(*sf);
    if (u != nullptr) {
        units.push_back(u);
        u->move(town->getPlacementCell());
    }

    return scene;
}

void Game::removeUnit(Unit* u) {
    units.erase(std::remove(units.begin(), units.end(), u), units.end());
}
