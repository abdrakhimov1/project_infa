//
// Created by fantom on 22.03.18.
//

#include "../Staff/allLibraries.h"
#include "../Logic/WorkWithPairs.h"
#include "../Resources/Dot.h"
#include "../Resources/Components.h"
#include "../Resources/GameObject.h"
#include "../Logic/IsIn.h"
#include "../Resources/resources.h"
#include "../Logic/Extractors.h"
#include "AnaliticGeometry.h"
#include "Physics.h"

void MoveObject(GameObject CurrentObject, float TimePassed){
    std::pair<float, float> CurrentSpeed = ExtractSpeed(CurrentObject);
    std::vector<Dot> DotVector = ExtractDots(CurrentObject);
    std::pair<float, float> Movement = CurrentSpeed*TimePassed;
    CurrentObject.getComponent<Collider>().calculateMassCentre().crs = CurrentObject.getComponent<Collider>().calculateMassCentre().crs + Movement;
    for (int j = 0; j < DotVector.size(); j++) {
        std::pair<float, float> CurrentCoordinates = DotVector[j].crs;
        std::pair<float, float> NewCoordinates = CurrentCoordinates + Movement;
        DotVector[j].crs = NewCoordinates;
    }
    CurrentObject.getComponent<Collider>().dotsList = DotVector;
};
//This one moves all dots of one object + MassCenter.

void RotateObject(GameObject object, float TimePassed){
    //FIXME
};
//Rotate object. Now unavailable. Quaternions?

void CheckForces(){
    //FIXME
};
//Find all forces, affecting all objects, and changes their speed. Now unavailable.

bool TheyCollided(GameObject Object1, GameObject Object2){
    int counter = 0;
    float x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    double tmp, maxSelf = 0, minOver, maxOver = 0;
    bool dotOnLeft = false, checked = false;
    GameObject* smallObject;
    GameObject* bigObject;
    //if (Object1.getComponent<Collider>().dotsList.size() < Object2.getComponent<Collider>().dotsList.size()) {
        smallObject = &Object1;
        bigObject = &Object2;
    /*}
    else{
        smallObject = &Object2;
        bigObject = &Object1;
    }
    */
    minOver = 10*(smallObject -> getComponent<Collider>().cellRadius);

    for (int i = 0; i < smallObject -> getComponent<Collider>().dotsList.size(); i++) {
        if (i == smallObject -> getComponent<Collider>().dotsList.size() - 1) {
            x1 = std::get<0>(smallObject -> getComponent<Collider>().dotsList[0].crs);
            y1 = std::get<1>(smallObject -> getComponent<Collider>().dotsList[0].crs);
        } else {
            x1 = std::get<0>(smallObject -> getComponent<Collider>().dotsList[i + 1].crs);
            y1 = std::get<1>(smallObject -> getComponent<Collider>().dotsList[i + 1].crs);
        }
        x0 = std::get<0>(smallObject -> getComponent<Collider>().dotsList[i].crs);
        y0 = std::get<1>(smallObject -> getComponent<Collider>().dotsList[i].crs);

        for (int k = 0; k < smallObject -> getComponent<Collider>().dotsList.size(); k++){
            float x = 0, y = 0;
            x = std::get<0>(smallObject -> getComponent<Collider>().dotsList[k].crs);
            y = std::get<1>(smallObject -> getComponent<Collider>().dotsList[k].crs);
            tmp = std::abs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - x0*y1)/std::sqrt(std::pow((y1 - y0), 2) + std::pow((x1 - x0), 2));
            if (tmp > maxSelf) {
                maxSelf = tmp;
                dotOnLeft = ((x1 - x0)*(y - y0) - (x - x0)*(y1 - y0) > 0);
            }
        }

        if (dotOnLeft) maxSelf *= -1;

        std::vector<Dot> dotsOnLeft, dotsOnRight;

        for (int n = 0; n < bigObject -> getComponent<Collider>().dotsList.size(); n++){
            float x = 0, y = 0;
            x = std::get<0>(bigObject -> getComponent<Collider>().dotsList[n].crs);
            y = std::get<1>(bigObject -> getComponent<Collider>().dotsList[n].crs);
            if ((x1 - x0)*(y - y0) - (x - x0)*(y1 - y0) > 0) {
                dotsOnLeft.push_back(bigObject -> getComponent<Collider>().dotsList[n]);
            }
            else {
                dotsOnRight.push_back(bigObject -> getComponent<Collider>().dotsList[n]);
            }
            tmp = std::abs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - x0*y1)/std::sqrt(std::pow((y1 - y0), 2) + std::pow((x1 - x0), 2));
            if (tmp < minOver) minOver = tmp;
            if (tmp > maxOver) maxOver = tmp;
        }

        if (dotsOnLeft.size()*dotsOnRight.size() != 0) {
            counter ++;
            checked = true;
        }

        dotsOnLeft.clear();
        dotsOnRight.clear();

        if (minOver < maxSelf and not checked) counter++;
    }

    if (counter == smallObject -> getComponent<Collider>().dotsList.size()) return true;

    return false;
};
//Inspect if two given objects have collided. Can work with convex collider.

void ElasticCollision(GameObject Object1, GameObject Object2){
    std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis = FindNewBasisForCollision(Object1, Object2);
    std::cout << getX(Object1.getComponent<RigidBody>().speed) << ' ' << getY(Object1.getComponent<RigidBody>().speed) << std::endl;
    std::cout << getX(Object2.getComponent<RigidBody>().speed) << ' ' << getY(Object2.getComponent<RigidBody>().speed) << std::endl;
    Object1.getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(Object1.getComponent<RigidBody>().speed, NewBasis);
    Object2.getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(Object2.getComponent<RigidBody>().speed, NewBasis);
    std::cout << getX(Object1.getComponent<RigidBody>().speed) << ' ' << getY(Object1.getComponent<RigidBody>().speed) << std::endl;
    std::cout << getX(Object2.getComponent<RigidBody>().speed) << ' ' << getY(Object2.getComponent<RigidBody>().speed) << std::endl;
    float Vx1 = std::get<0>(Object1.getComponent<RigidBody>().speed);
    float Vy1 = std::get<1>(Object1.getComponent<RigidBody>().speed);
    float m1 = Object1.getComponent<RigidBody>().mass;
    float Vx2 = std::get<0>(Object2.getComponent<RigidBody>().speed);
    float Vy2 = std::get<1>(Object2.getComponent<RigidBody>().speed);
    float m2 = Object2.getComponent<RigidBody>().mass;
    float P0 = Vx1*m1 + Vx2*m2;
    double E0 = m1*std::pow(Vx1, 2) + m2*std::pow(Vx2, 2);
    std::pair<float, float> newObjectsXSpeeds = solveEqulationSystem(P0, E0, m1, m2, Vx2);
    Vx1 = std::get<0>(newObjectsXSpeeds);
    Vx2 = std::get<1>(newObjectsXSpeeds);
    std::cout << Vx1 << ' ' << Vy1 << std::endl;
    std::cout << Vx2 << ' ' << Vy2 << std::endl;
    std::pair<std::pair<float, float>, std::pair<float, float>> oldBasis = findMainBasisCoords(NewBasis);
    Object1.getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(std::make_pair(Vx1, Vy1), oldBasis);
    Object2.getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(std::make_pair(Vx2, Vy2), oldBasis);
    std::cout << getX(Object1.getComponent<RigidBody>().speed) << ' ' << getY(Object1.getComponent<RigidBody>().speed) << std::endl;
    std::cout << getX(Object2.getComponent<RigidBody>().speed) << ' ' << getY(Object2.getComponent<RigidBody>().speed) << std::endl;
    };
//Model of elastic collision
//FIXME - must consider geometry and rotation


void NonElasticCollision(GameObject Object1, GameObject Object2){
    //FIXME
};
//Model of nonelastic collision

void SolveCollision(GameObject Object1, GameObject Object2){
    float AdditionalTime = 0;
    double step = 0.05*(Resources::getInstance().CurrentFrameTime - Resources::getInstance().LastFrameTime);
    std::cout << "Collision detected" << std::endl;
    while (TheyCollided(Object1, Object2), TheyCollided(Object2, Object1)){
        MoveObject(Object1, -1*step);
        MoveObject(Object2, -1*step);
        AdditionalTime += step;
    }
    std::cout << "I'm in SolveCollision, cycle ended" << std::endl;
    ElasticCollision(Object1, Object2);
    if (Object1.getComponent<RigidBody>().unmovable) Object1.getComponent<RigidBody>().speed = std::make_pair(0, 0);
    if (Object2.getComponent<RigidBody>().unmovable) Object2.getComponent<RigidBody>().speed = std::make_pair(0, 0);
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
            float xc1 = std::get<0>(objects[i].getComponent<Collider>().calculateMassCentre().crs);
            float yc1 = std::get<1>(objects[i].getComponent<Collider>().calculateMassCentre().crs);
            float r1 = objects[i].getComponent<Collider>().cellRadius;
            for (int j = i + 1; j < objects.size(); j++) {
                if (IsIn<Collider>(objects[j])) {
                    float xc2 = std::get<0>(objects[j].getComponent<Collider>().calculateMassCentre().crs);
                    float yc2 = std::get<1>(objects[j].getComponent<Collider>().calculateMassCentre().crs);
                    float r2 = objects[j].getComponent<Collider>().cellRadius;
                    if (std::sqrt(std::pow(xc2 - xc1, 2) + std::pow(yc2 - yc1, 2)) < r1 + r2) {
                        if (TheyCollided(objects[i], objects[j]) and TheyCollided(objects[j], objects[i]))
                            SolveCollision(objects[i], objects[j]);
                    }
                }
            }
        }
    }
};
//Find and solve collisions

void MoveColliders(){
    while (Window::getWindow().isOpen()) {
        Resources::getInstance().accessToResources2.lock();
        Resources::getInstance().LastFrameTime = Resources::getInstance().CurrentFrameTime;
        Resources::getInstance().CurrentFrameTime = Resources::getInstance().Timer.getElapsedTime().asSeconds();
        std::vector<GameObject> ObjectVector = Resources::getInstance().Objects;
        float TimePassed = Resources::getInstance().CurrentFrameTime - Resources::getInstance().LastFrameTime;
        CheckForces();
        for (int i = 0; i < ObjectVector.size(); i++) {
            MoveObject(ObjectVector[i], TimePassed);
        }
        CheckCollisions();
        Resources::getInstance().accessToResources2.unlock();
        while (Window::getWindow().pollEvent(Resources::getInstance().event)) {
            switch (Resources::getInstance().event.type) {
                case sf::Event::Closed:
                    Window::getWindow().close();
                    break;
            }
        }
    }
};
//MoveDots and RotateObjects and checks everything in case of collisions. Also will contain Gravity and some effects.
