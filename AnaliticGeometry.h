//
// Created by fantom on 06.04.18.
//
#include "WorkWithPairs.h"
#include "GameObject.h"
#ifndef PROJECT_INFA_ANALITICGEOMETRY_H
#define PROJECT_INFA_ANALITICGEOMETRY_H

std::pair<float, float> FindVectorCoordinatesInNewBasis(std::pair<float, float> Vector,
                                                        std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis);

std::pair<std::pair<float, float>, std::pair<float, float>> FindNewBasisForCollision(GameObject Object1, GameObject Object2);

#endif //PROJECT_INFA_ANALITICGEOMETRY_H
