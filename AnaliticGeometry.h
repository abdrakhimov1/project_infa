//
// Created by fantom on 06.04.18.
//

#include "allLibraries.h"
#include "WorkWithPairs.h"
#include "Dot.h"
#include "GameObject.h"

#ifndef PROJECT_INFA_ANALITICGEOMETRY_H
#define PROJECT_INFA_ANALITICGEOMETRY_H

std::pair<float, float> FindVectorCoordinatesInNewBasis(std::pair<float, float> Vector,
                                                        std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis);

std::pair<std::pair<float, float>, std::pair<float, float>> FindNewBasisForCollision(GameObject Object1, GameObject Object2);

float operator-(Dot dot1, Dot dot2);

std::pair<std::pair<float, float>, std::pair<float, float>> findMainBasisCoords(std::pair<std::pair<float, float>, std::pair<float, float>> Basis);

std::pair<float, float> solveEqulationSystem(float P0, float E0, float m1, float m2, float Vx2_0);

#endif //PROJECT_INFA_ANALITICGEOMETRY_H
