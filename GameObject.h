//
// Created by fantom on 06.04.18.
//

#ifndef PROJECT_INFA_GAMEOBJECT_H
#define PROJECT_INFA_GAMEOBJECT_H

#include <vector>
#include "Components.h"
#include <cstring>

class GameObject{
public:
    std::vector<AbstractComponent*> componentsList;

    template <typename T>
    void addComponent();

    template <typename T>
    T& getComponent();
};

#endif //PROJECT_INFA_GAMEOBJECT_H
