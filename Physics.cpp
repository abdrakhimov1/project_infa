//
// Created by fantom on 22.03.18.
//
#include "GameObject.cpp"
#include "resourses.cpp"
#include <vector>
#include <utility>

std::pair<float, float> SummPairs(std::pair<float, float> FirstPair, std::pair<float, float> SecondPair)
{
    float TMP1 = std::get<0>(FirstPair) + std::get<0>(SecondPair);
    float TMP2 = std::get<1>(FirstPair) + std::get<1>(SecondPair);
    return std::make_pair(TMP1, TMP2);
};

std::pair<float, float> MultiplyPair(std::pair<float, float> Pair, float Constant)
{
    float TMP1 = std::get<0>(Pair)*Constant;
    float TMP2 = std::get<1>(Pair)*Constant;
    return std::make_pair(TMP1, TMP2);
};

std::pair<float, float> ExtractSpeed(GameObject object)
{
    return make_pair(0, 0); //FIXME
};

void MoveCenters()
//This one moves centers of all objects. Pretty useless till we don't rotate objects.
{
    resourses = Resources::getInstance();
    std::vector<GameObject> ObjectVector = resourses.Objects;
    float TimePassed = resourses.CurrentFrameTime - resourses.LastFrameTime;
    for (int i = 0; i < ObjectVector.size(); i++)
    {
        GameObject CurrentObject = ObjectVector[i];
        std::pair<float, float> CurrentSpeed = ExtractSpeed(CurrentObject);  //Here must be extraction of speed
        // from map of components. Function must contain Fool Protection and return (0, 0) if object has no speed.
        std::pair<float, float> CurrentCoordinates = CurrentObject.CenterCoordinates;
        std::pair<float, float> Movement = MultiplyPair(CurrentSpeed, TimePassed);
        std::pair<float, float> NewCoordinates = SummPairs(CurrentCoordinates, Movement);
        CurrentObject.CenterCoordinates = NewCoordinates;
    }
}

void MoveVector()
//Gets vector, move and rotate it with needed speed and moment for needed time.
{
    //FIXME
}

void MoveColliders()
{
    //Talk to Danya about how to better organize collider form.
}

#include "Physics.h"
