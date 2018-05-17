//
// Created by fantom on 06.04.18.
//
#include "../Staff/allLibraries.h"
#include "../Logic/WorkWithPairs.h"

#ifndef PROJECT_INFA_DOT_H
#define PROJECT_INFA_DOT_H

class Dot{
public:
    Dot(float x, float y);
    Dot();
    std::pair < float, float > crs;
};

#endif //PROJECT_INFA_DOT_H
