//
// Created by fantom on 06.04.18.
//

#ifndef PROJECT_INFA_ANALITICGEOMETRY_H
#define PROJECT_INFA_ANALITICGEOMETRY_H

std::pair<float, float> FindVectorCoordinatesInNewBasis(std::pair<float, float> Vector,
                                                        std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis);

std::pair<std::pair<float, float>, std::pair<float, float>> FindNewBasisForCollision(GameObject Object1, GameObject Object2);

float operator-(Dot dot1, Dot dot2);

#endif //PROJECT_INFA_ANALITICGEOMETRY_H
