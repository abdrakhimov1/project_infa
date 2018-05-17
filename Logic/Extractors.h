//
// Created by fantom on 06.04.18.
//

#include "../Resources/GameObject.h"
#include "WorkWithPairs.h"
#include "../Staff/allLibraries.h"
#include "../Resources/Dot.h"
#include "IsIn.h"

#ifndef PROJECT_INFA_EXTRACTORS_H
#define PROJECT_INFA_EXTRACTORS_H

std::pair<float, float> ExtractSpeed(GameObject object);

std::vector<Dot> ExtractDots(GameObject object);

#endif //PROJECT_INFA_EXTRACTORS_H
