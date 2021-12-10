#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

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

#include "terrain/river.hpp"
#include "terrain/mountain.hpp"
#include "terrain/hill.hpp"
#include "terrain/spike.hpp"

#include "item/sharpeningStone.hpp"
#include "item/armorPlates.hpp"
#include "item/medicalSupplies.hpp"

void clearScreen();
Scene* initDefaultScene();
void buildUnit(Town*, UnitFactory*, std::vector<Unit*>&);

Game::~Game() {
    // TODO: Do memory stuff and stuff
    GameObject::freeAllObjects();
}

void Game::begin() {
    clearScreen();
    
    scene = initDefaultScene();
    SwordsmanFactory* swordsmanF = new SwordsmanFactory();
    SpearmanFactory* spearmanF = new SpearmanFactory();
    ArcherFactory* archerF = new ArcherFactory();
    CrossbowmanFactory* crossbowmanF = new CrossbowmanFactory();
    HorsemanFactory* horsemanF = new HorsemanFactory();
    KnightFactory* knightF = new KnightFactory();

    // TODO: DELETE AFTER TESTING
    
    buildUnit(town, swordsmanF, units);
    
    // Game loop:
    while (true) {
        // Check object limit
        while (GameObject::getObjectCount() > getObjectLimit())
            GameObject::freeNewestObject();

        // Remove dead units  TODO: Inefficient, use observer
        for (Unit* unit : units) {
            if (!unit->isAlive()) {
                delete unit;
            }
        }

        // Draw screen
        draw(*scene);
    
        // Draw menu
        std::cout << "Objects: " << GameObject::getObjectCount() << '/'
                  << getObjectLimit() << std::endl;

        std::cout << "Town units: " << town->getOwnedUnits() << '/'
                  << town->getMaxUnits() << std::endl;

        for (size_t i = 0; i < units.size(); i++) {
            std::cout << i << ": " << units[i]->getGraphics()
                      << "  df=" << units[i]->getDefense()
                      << "  dm=" << units[i]->getDamage()
                      << "  hp=" << units[i]->getHealth()
                      << '/' << units[i]->getMaxHealth()
                      << std::endl;
        }

        std::cout << "\nCommand syntax: <command><unit_number>\n";
        std::cout << "(h j k l) move\n(y u i o) attack\n" << 
                     "(s p a c r n) make unit\n(d) delete unit\n";

        // Capture input
        char command;
        unsigned selection;

        std::cin >> command >> selection;

        // FIX: Unable to produce units when units vector is empty
        // Validate input
        while (std::cin.fail() || selection >= units.size()) {
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input." << std::endl;
            std::cin >> command >> selection;
        }
        
        // React to input
        switch (command) {
            // Movement
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
            // Produce unit
            case 's':
                buildUnit(town, swordsmanF, units);
                break;
            case 'p':
                buildUnit(town, spearmanF, units);
                break;
            case 'a':
                buildUnit(town, archerF, units);
                break;
            case 'c':
                buildUnit(town, crossbowmanF, units);
                break;
            case 'r':
                buildUnit(town, horsemanF, units);
                break;
            case 'n':
                buildUnit(town, knightF, units);
                break;
            // Delete unit
            case 'd':
                delete units[selection];
                break;
            // Attacks
            case 'y':
                units[selection]->attackWest();
                break;
            case 'u':
                units[selection]->attackSouth();
                break;
            case 'i':
                units[selection]->attackNorth();
                break;
            case 'o':
                units[selection]->attackEast();
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
            else if (cell->getItem() != nullptr)
                std::cout << cell->getItem()->getGraphics() << ' ';
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
    std::system ("clear");
#endif
}

void buildUnit(Town* t, UnitFactory* f, std::vector<Unit*>& units) {
    Unit* u = t->produce(*f);
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

    Item* armor = new ArmorPlates();
    scene->getCell(4, 2).setItem(armor);

    Item* damage = new SharpeningStone();
    scene->getCell(6, 2).setItem(damage);

    Item* ultimateHealth = new MedicalSupplies(900);
    scene->getCell(8, 2).setItem(ultimateHealth);

    Item* health = new MedicalSupplies();
    scene->getCell(10, 2).setItem(health);

    return scene;
}

void Game::removeUnit(Unit* u) {
    units.erase(std::remove(units.begin(), units.end(), u), units.end());
}
