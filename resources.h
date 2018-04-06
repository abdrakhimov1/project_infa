//
// Created by fantom on 06.04.18.
//
#include <SFML/Graphics.hpp>
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
    float CurrentFrameTime;
    float LastFrameTime;

    void addObject(GameObject object);
    static Resources& getInstance();
};

#endif //PROJECT_INFA_RESOURCES_H
