//
// Created by fantom on 22.03.18.
//
#include "GameObject.cpp"
#include "resourses.cpp"
#include <vector>

void movement()
{
    resourses = Resources::getInstance();
    std::vector<GameObject> ObjectVector = resourses.Objects; // FIXME
    for (int i = 0; i < ObjectVector.size(); i++)
    {
        GameObject CurrentObject = ObjectVector[i];
        std::pair<std::string, int> CurrentSpeed = CurrentObject.components.ExtractSpeed;  //Here must be extraction of speed from map of components
        int CurrentCoordinates = CurrentObject.matrix;          //Talk to Danya about structure of GameObject

    }
}

#include "Physics.h"
