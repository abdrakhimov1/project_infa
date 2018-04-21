//
// Created by fantom on 06.04.18.
// Modified by verwindle on 07.04.18.
//
#include "allLibrares.h"
#include "GameObject.h"
#ifndef PROJECT_INFA_RESOURCES_H
#define PROJECT_INFA_RESOURCES_H

class Resources
{
private:
    Resources();
    Resources( const Resources&);

public:

    std::vector<GameObject> Objects;
    sf::RenderWindow* window;

    sf::RenderWindow& getWindow();
    void clearWindow();
    void displayWindow();

    float CurrentFrameTime;
    float LastFrameTime;

    void addObject(GameObject object);
    static Resources& getInstance();
};

#endif //PROJECT_INFA_RESOURCES_H
