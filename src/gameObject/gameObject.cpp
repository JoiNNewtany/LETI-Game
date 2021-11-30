#include "gameObject.hpp"
#include <list>

std::list<GameObject*> GameObject::objects;

GameObject::GameObject() {
    objects.push_back(this);
}

GameObject::~GameObject() {
    objects.remove(this);
    notify();
}

void GameObject::freeOldestObject() {
    delete objects.front();
}

void GameObject::freeNewestObject() {
    delete objects.back();
}

void GameObject::freeAllObjects() {
    for (GameObject* object : objects) {
        delete object;
    }
}
