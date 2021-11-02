#include "gameObject.hpp"
#include <list>

std::list<GameObject*> GameObject::objects;

GameObject::GameObject() {
    //
}

GameObject::~GameObject() {
    //
}

void GameObject::freeAllObjects() {
    for (GameObject* object : objects) {
        delete object;
    }
}
