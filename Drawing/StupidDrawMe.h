//
// Created by verwindle on 11.04.18.
//
#include "../Resources/Components.h"
#include "../Resources/Triangle.h"

#ifndef PROJECT_INFA_STUPIDDRAWME_H
#define PROJECT_INFA_STUPIDDRAWME_H

class StDrawMe : public AbstractComponent{
public:
    StDrawMe(Triangle triangle);


    ~StDrawMe();
};

#endif //PROJECT_INFA_STUPIDDRAWME_H