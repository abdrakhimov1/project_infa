//
// Created by verwindle on 12.04.18.
//
#include "allLibraries.h"
#include "Dot.h"
#include "WorkWithPairs.h"

#ifndef PROJECT_INFA_SPRITE_H
#define PROJECT_INFA_SPRITE_H

class GameObject;

class Sprite {
private:

    sf::Sprite sprite;
    sf::ConvexShape convex;
    sf::Texture texture;
    Dot centre;
public:
    Sprite(GameObject& object);

    const std::string obj_name;
    sf::Texture setTexture();
  
    std::vector<Dot> dots;
    unsigned long quantity_of_dots;

    std::vector<Dot> crs;
    sf::Color mask_color = sf::Color::Black; // collision mask

    void draw();
};

#endif //PROJECT_INFA_SPRITE_H