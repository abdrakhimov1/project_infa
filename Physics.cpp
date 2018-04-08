//
// Created by fantom on 22.03.18.
//

#include <iostream>
#include <cmath>
#include "Dot.h"
#include "Physics.h"
#include "IsIn.h"
#include "resources.h"
#include "Extractors.h"
#include "AnaliticGeometry.h"

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

void ElasticCollision(GameObject Object1, GameObject Object2){
    std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis = FindNewBasisForCollision(Object1, Object2);
    Object1.getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(Object1.getComponent<RigidBody>().speed, NewBasis);
    Object2.getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(Object2.getComponent<RigidBody>().speed, NewBasis);
    Vx1 = std::get<0>(Object1.getComponent<RigidBody>().speed);
    Vy1 = std::get<1>(Object1.getComponent<RigidBody>().speed);
    m1 = Object1.getComponent<RigidBody>().mass;
    Vx2 = std::get<0>(Object2.getComponent<RigidBody>().speed);
    Vy2 = std::get<1>(Object2.getComponent<RigidBody>().speed);
    m2 = Object2.getComponent<RigidBody>().mass;
    float P0 = Vx1*m1 + Vx2*m2;
    float E0 = m1*std::pow(Vx1, 2) + m2*std::pow(Vx2, 2);

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
            float xc1 = std::get<0>(objects[i].getComponent<Collider>().massCentre.crs);
            float yc1 = std::get<1>(objects[i].getComponent<Collider>().massCentre.crs);
            float r1 = objects[i].getComponent<Collider>().cellRadius;
            for (int j = i + 1; j < objects.size(); j++) {
                if (IsIn<Collider>(objects[j])) {
                    float xc2 = std::get<0>(objects[j].getComponent<Collider>().massCentre.crs);
                    float yc2 = std::get<1>(objects[j].getComponent<Collider>().massCentre.crs);
                    float r2 = objects[j].getComponent<Collider>().cellRadius;
                    if (std::sqrt(std::pow(xc2 - xc1, 2) + std::pow(yc2 - yc1, 2)) < r1 + r2) {
                        if (TheyCollided(objects[i], objects[j]))
                            SolveCollision(objects[i], objects[j]);
                    }
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
