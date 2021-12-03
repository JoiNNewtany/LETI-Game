#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#include "game.hpp"
#include "gameObject/gameObject.hpp"
#include "scene/scene.hpp"

#include "unit/building/town.hpp"
#include "unit/unitFactory.hpp"
#include "unit/infantry/swordsmanFactory.hpp"
#include "unit/infantry/spearmanFactory.hpp"
#include "unit/ranged/archerFactory.hpp"
#include "unit/ranged/crossbowmanFactory.hpp"
#include "unit/cavalry/horsemanFactory.hpp"
#include "unit/cavalry/knightFactory.hpp"

#include "terrain/terrain.hpp"
#include "terrain/river.hpp"
#include "terrain/mountain.hpp"
#include "terrain/hill.hpp"
#include "terrain/spike.hpp"

void clearScreen();
Scene* initDefaultScene();
void buildUnit(Town*, SwordsmanFactory*, std::vector<Unit*>&);

Game::~Game() {
    // TODO: Do memory stuff and stuff
    GameObject::freeAllObjects();
}

void Game::begin() {
    clearScreen();
    
    scene = initDefaultScene();
    SwordsmanFactory* sf = new SwordsmanFactory();

    // TODO: DELETE AFTER TESTING
    
    buildUnit(town, sf, units);
    
    // Game loop:
    while (true) {
        // Check object limit
        while (GameObject::getObjectCount() > getObjectLimit())
            GameObject::freeNewestObject();

        // Remove dead units
        for (Unit* unit : units) {
            if (!unit->isAlive()) {
                delete unit;
            }
        }

        // Draw screen
        draw(*scene);
    
        // Draw menu
        std::cout << "Objects: " << GameObject::getObjectCount() << '/'
                  << getObjectLimit() << '\n';

        std::cout << "Town units: " << town->getOwnedUnits() << '/'
                  << town->getMaxUnits() << '\n';

        if (!units.empty())
            std::cout << "Unit[0] stats: df=" << units[0]->getDefense()
                  << "  dm=" << units[0]->getDamage() << "  hp="
                  << units[0]->getHealth() << "\n\n";

        for (size_t i = 0; i < units.size(); i++) {
            std::cout << i << ": " << units[i]->getGraphics() << std::endl;
        }

        std::cout << "\nCommand syntax: <command><unit_number>\n";
        std::cout << "(h j k l) move\n(u) make unit\n(d) delete unit\n";

        // Capture input
        char command;
        unsigned selection;

        std::cin >> command >> selection;
        // if end of cin, do switch, else input selection?
        
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
                buildUnit(town, sf, units);
                break;
            case 'd':
                delete units[selection];
                break;
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
            else if (cell->getTerrain() != nullptr)
                std::cout << cell->getTerrain()->getGraphics() << ' ';
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

void buildUnit(Town* t, SwordsmanFactory* sf, std::vector<Unit*>& units) {
    Unit* u = t->produce(*sf);
    if (u != nullptr) {
        units.push_back(u);
        u->move(t->getPlacementCell());
    }
}

Scene* Game::initDefaultScene() {
    Scene* scene = new Scene(12);
    
    // Place units

    town = new Town();
    town->move(&scene->getCell(6, 9));

    // Place terrain

    Terrain* river = new River();
    scene->getCell(4, 4).setTerrain(river);

    Terrain* mountain = new Mountain();
    scene->getCell(6, 4).setTerrain(mountain);

    Terrain* hill = new Hill();
    scene->getCell(8, 4).setTerrain(hill);

    Terrain* spike = new Spike();
    scene->getCell(10, 4).setTerrain(spike);

    // Place items

    return scene;
}

void Game::removeUnit(Unit* u) {
    units.erase(std::remove(units.begin(), units.end(), u), units.end());
}
