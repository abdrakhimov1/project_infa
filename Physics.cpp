//
// Created by fantom on 22.03.18.

#include <vector>
#include <utility>
#define resourses Resources::getInstance()

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
//Extract speed from map of components
{
    return std::make_pair(0, 0); //FIXME
};

std::vector<Dot> ExtractDots(GameObject object)
//Extracts vector of dots from map of components
{
    //FIXME
}

void MoveDots()
//This one moves all dots of all objects. And also will be RotateObjects. It will start working after move is done.
{
    std::vector<GameObject> ObjectVector = resourses.Objects;
    float TimePassed = resourses.CurrentFrameTime - resourses.LastFrameTime;
    for (int i = 0; i < ObjectVector.size(); i++)
    {
        GameObject CurrentObject = ObjectVector[i];
        std::pair<float, float> CurrentSpeed = ExtractSpeed(CurrentObject);
        std::vector<Dot> DotVector = ExtractDots(CurrentObject);
        for (int j = 0; j < DotVector.size(); j++) {
            std::pair<float, float> CurrentCoordinates = DotVector[j].crs;
            std::pair<float, float> Movement = MultiplyPair(CurrentSpeed, TimePassed);
            std::pair<float, float> NewCoordinates = SummPairs(CurrentCoordinates, Movement);
            DotVector[j].crs = NewCoordinates;
        }
    }
}

void RotateObjects()
//Gets objects and rotate them according to their moments of movement
{
    //FIXME
}

void MoveColliders()
//Calls MoveDots and RotateObjects and checks everything in case of collisions
{
    //FIXME
}

#include "Physics.h"
