//
// Created by fantom on 06.04.18.
//

#include "Extractors.h"
#include "IsIn.h"

std::pair<float, float> ExtractSpeed(GameObject object) {
    std::pair<float, float> speed;
    if (IsIn<RigidBody>(object)) {
        return object.getComponent<RigidBody>().speed;
    }
    return std::make_pair(0, 0);
};
//Extract speed from GameObject

std::vector<Dot> ExtractDots(GameObject object){
    if (IsIn<Collider>(object)){
        return object.getComponent<Collider>().dotsList;
    }
    std::vector<Dot> EmptyAnswer;
    return EmptyAnswer;
};
//Extracts vector of dots from GameObject