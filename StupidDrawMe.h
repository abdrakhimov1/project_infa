//
// Created by verwindle on 11.04.18.
//
#include "Components.h"
#include "StupidRendering.h"

#ifndef PROJECT_INFA_STUPIDDRAWME_H
#define PROJECT_INFA_STUPIDDRAWME_H

class DrawMe : public AbstractComponent{
public:
    DrawMe(Triangle triangle()) {
    Resources::getInstance().clearWindow();
    triangle.draw();
    Resources::getInstance().displayWindow();
};

    ~DrawMe() {
    Resources::getInstance().clearWindow();
    Resources::getInstance().displayWindow();
};
};

#endif //PROJECT_INFA_STUPIDDRAWME_H