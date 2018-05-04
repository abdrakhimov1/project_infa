//
// Created by fantom on 06.04.18.
// Modified by verwindle on 07.04.18.
//

#include "allLibraries.h"
#include "GameObject.h"
#include "Window.h"
#ifndef PROJECT_INFA_RESOURCES_H
#define PROJECT_INFA_RESOURCES_H

class Resources{
private:
    Resources();
public:
    std::vector<GameObject> Objects;
    sf::Clock Timer;
    float CurrentFrameTime;
    float LastFrameTime;
    std::mutex accessToResourses;
    void addObject(GameObject object);
    static Resources& getInstance();
};

#endif //PROJECT_INFA_RESOURCES_H
