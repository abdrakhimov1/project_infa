//
// Created by verwindle on 11.04.18.
//
#include "GameObject.h"
#include "WorkWithPairs.h"

#ifndef PROJECT_INFA_STUPIDRENDERING_H
#define PROJECT_INFA_STUPIDRENDERING_H

sf::Vector2f getVectorFromPair(std::pair<float, float> coords);

Dot setSpriteCentre(GameObject object, std::vector<Dot> dots);

class Triangle {
private:
    sf::CircleShape triangle(100, 3);
    Dot centre;
    float mean_x;
    float mean_y;
public:
   Triangle(GameObject object) {};
    sf::Color Dan_favourite_color = sf::Color(7, 55, 221);                     
    
    void draw();
};

#endif //PROJECT_INFA_STUPIDRENDERING_H