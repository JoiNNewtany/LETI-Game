#pragma once

#include <list>
#include "observer/publisher.hpp"

class GameObject : public Publisher {
    // Stores pointers to all created objects
    static std::list<GameObject*> objects;

    public:
        GameObject();
        virtual ~GameObject();

        static unsigned getObjectCount() { return objects.size(); }
        static void freeOldestObject();
        static void freeNewestObject();
        static void freeAllObjects();

    protected:
        char graphics;
};
