#pragma once

#include <list>

class GameObject {
    // Stores pointers to all created objects
    static std::list<GameObject*> objects;

    public:
        GameObject();
        ~GameObject();

        static unsigned getObjectCount() { return objects.size(); }
        static void freeOldestObject() { objects.pop_front(); }
        static void freeNewestObject() { objects.pop_back(); }
        static void freeAllObjects();

    protected:
        bool collides;
        char graphics;
};
