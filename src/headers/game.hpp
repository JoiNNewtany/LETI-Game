#pragma once

class Game {
    public:
        Game();
        //Game(Scene);

        void begin();
        void end();

        ~Game();
    private:
        void draw();
};
