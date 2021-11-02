#include <iostream>
#include "game/game.hpp"

int main() {
    Game& game = Game::instance();
    
    game.begin();

    return 0;
}
