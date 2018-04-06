//
// Created by fantom on 22.03.18.
//

#include <iostream>
#include <cmath>
#include "Dot.h"
#include "Physics.h"
#include "IsIn.h"
#include "resources.h"

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

void MoveObject(GameObject CurrentObject, float TimePassed){
    std::pair<float, float> CurrentSpeed = ExtractSpeed(CurrentObject);
    std::vector<Dot> DotVector = ExtractDots(CurrentObject);
    std::pair<float, float> Movement = CurrentSpeed*TimePassed;
    CurrentObject.getComponent<Collider>().massCentre.crs = CurrentObject.getComponent<Collider>().massCentre.crs + Movement;
    for (int j = 0; j < DotVector.size(); j++) {
        std::pair<float, float> CurrentCoordinates = DotVector[j].crs;
        std::pair<float, float> NewCoordinates = CurrentCoordinates + Movement;
        DotVector[j].crs = NewCoordinates;
    }
};
//This one moves all dots of one object + MassCenter.

void RotateObject(GameObject object, float TimePassed){
    //FIXME
};
//Rotate object. Now unavailable

void CheckForces(){
    //FIXME
};
//Find all forces, affecting all objects, and changes their speed. Now unavailable

bool TheyCollided(GameObject Object1, GameObject Object2){
    int counter = 1;
    float x, y, x0, y0, x1, y1, a = 0, b = 0;       //y = a*x + b
    for (int i = 0; i < Object1.getComponent<Collider>().dotsList.size(); i++){
        if (i == Object1.getComponent<Collider>().dotsList.size() - 1){
            x1 = std::get<0>(Object1.getComponent<Collider>().dotsList[0].crs);
            y1 = std::get<1>(Object1.getComponent<Collider>().dotsList[0].crs);
        }
        else{
            x1 = std::get<0>(Object1.getComponent<Collider>().dotsList[i + 1].crs);
            y1 = std::get<1>(Object1.getComponent<Collider>().dotsList[i + 1].crs);
        }
        x1 = std::get<0>(Object1.getComponent<Collider>().dotsList[i].crs);
        y1 = std::get<1>(Object1.getComponent<Collider>().dotsList[i].crs);
        if (x1 != x0) {
            a = (y1 - y0) / (x1 - x0);
            b = (y0 * x1 - y1 * x0);
        }
        for (int j = 0; j < Object2.getComponent<Collider>().dotsList.size(); j++){
            x = std::get<0>(Object2.getComponent<Collider>().dotsList[j].crs);
            y = std::get<1>(Object2.getComponent<Collider>().dotsList[j].crs);
            if (x1 != x0 and (y - (a*x + b))*(x1 - x0) < 0) counter++;
            if (x1 == x0 and (x - x0)*(y1 - y0) < 0) counter++;
        }
    }
    return counter == Object1.getComponent<Collider>().dotsList.size();
};
//Inspect if two given objects have collided. Can work with convex collider.

void MoveSpeedToNewCoords(GameObject Object, std::pair<float, float> X, std::pair<float, float> Y){
    float Vx0, Vy0, Vx1, Vy1, x1, y1, x2, y2;
    Vx0 = std::get<0>(Object.getComponent<RigidBody>().speed);
    Vy0 = std::get<1>(Object.getComponent<RigidBody>().speed);
    x1 = std::get<0>(X);
    x2 = std::get<1>(X);
    y1 = std::get<0>(Y);
    y2 = std::get<1>(Y);
    Vy1 = (Vy0*x1 - Vx0*y1)/(x1*y2 - x2*y1);
    Vx1 = Vx0/x1 - Vy1*x2/x1;
    Object.getComponent<RigidBody>().speed = std::make_pair(Vx1, Vy1);
};
//Some technical shit, don't touch it

void GoToNewCoords(GameObject Object1, GameObject Object2){
    std::pair<float, float> FirstCenter = Object1.getComponent<Collider>().massCentre.crs;
    std::pair<float, float> SecondCenter = Object2.getComponent<Collider>().massCentre.crs;
    std::pair<float, float> X = SecondCenter + FirstCenter*(-1);
    float norm = std::sqrt(std::get<0>(X)*std::get<0>(X) + std::get<1>(X)*std::get<1>(X));
    X = X*(1/norm);
    float x0 = std::get<0>(X);
    float x1 = std::get<1>(X);
    float y1, y0;
    if (std::get<0>(X) >= 0){
        y1 = std::sqrt(1/(x0*x0 + x1*x1))*x0;
        y0 = -1*x1*y1/x0;
    }
    else{
        y1 = -1*std::sqrt(1/(x0*x0 + x1*x1))*x0;
        y0 = -1*x1*y1/x0;
    }
    std::pair<float, float> Y = std::make_pair(y0, y1);
    MoveSpeedToNewCoords(Object1, X, Y);
    MoveSpeedToNewCoords(Object2, X, Y);
};
//This one too

void ElasticCollision(GameObject Object1, GameObject Object2){
    GoToNewCoords(Object1, Object2);
    float P0 = std::get<0>(Object1.getComponent<RigidBody>().speed)*Object1.getComponent<RigidBody>().mass +
            std::get<0>(Object2.getComponent<RigidBody>().speed)*Object2.getComponent<RigidBody>().mass;
    float E0 = (std::pow(std::get<0>(Object1.getComponent<RigidBody>().speed), 2) +
            std::pow(std::get<1>(Object1.getComponent<RigidBody>().speed), 2))*Object1.getComponent<RigidBody>().mass +
            (std::pow(std::get<0>(Object2.getComponent<RigidBody>().speed), 2) +
                    std::pow(std::get<1>(Object2.getComponent<RigidBody>().speed), 2))*Object2.getComponent<RigidBody>().mass;
    //FIXME - here must be solution of equation system, but I dunno one of needed conditions
    };
//Model of elastic collision
//FIXME - must consider geometry and rotation

void NonElasticCollision(GameObject Object1, GameObject Object2){
    //FIXME
};
//Model of nonelastic collision

void SolveCollision(GameObject Object1, GameObject Object2){
    float AdditionalTime = 0;
    float step = 0.005*(Resources::getInstance().CurrentFrameTime - Resources::getInstance().LastFrameTime);
    while (TheyCollided(Object1, Object2)){
        MoveObject(Object1, -1*step);
        MoveObject(Object2, -1*step);
        AdditionalTime += step;
    }
    ElasticCollision(Object1, Object2);
    MoveObject(Object1, AdditionalTime);
    MoveObject(Object2, AdditionalTime);
};
//Universal collision solver.
//FIXME - Add ability to work with unmovable objects and non-elastic collisions. Add individual solutions.
//FIXME - Needs to be rebuilt completely

void CheckCollisions(){
    std::vector<GameObject> objects = Resources::getInstance().Objects;
    for (int i = 0; i < objects.size(); i++) {
        if (IsIn<Collider>(objects[i])) {
            for (int j = i + 1; j < objects.size(); j++) {
                if (IsIn<Collider>(objects[j])) {
                    if (TheyCollided(objects[i], objects[j]))
                        SolveCollision(objects[i], objects[j]);
                }
            }
        }
    }
};
//Find and solve collisions

void MoveColliders(){
    std::vector<GameObject> ObjectVector = Resources::getInstance().Objects;
    float TimePassed = Resources::getInstance().CurrentFrameTime - Resources::getInstance().LastFrameTime;
    CheckForces();
    for (int i = 0; i < ObjectVector.size(); i++) {
        MoveObject(ObjectVector[i], TimePassed);
    }
    CheckCollisions();
};
//MoveDots and RotateObjects and checks everything in case of collisions. Also will contain Gravity and some effects.
//Must work in cycle
