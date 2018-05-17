//
// Created by verwindle on 11.04.18.
//
#include "../Staff/allLibraries.h"
#include "Dot.h"
#include "../Logic/WorkWithPairs.h"

#ifndef PROJECT_INFA_STUPIDRENDERING_H
#define PROJECT_INFA_STUPIDRENDERING_H


class Triangle {
private:
    sf::CircleShape triangle;
public:
   Triangle();

    static Dot triangleMassCentre();

    Dot setSpriteCentre();

    sf::Color Dan_favourite_color = sf::Color(7, 55, 221);                     
    
    void draw();
};


#endif //PROJECT_INFA_STUPIDRENDERING_H