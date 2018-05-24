//
// Created by fantom on 17.05.18.
//

#include "Physics2.0.h"

void MoveObject(GameObject* CurrentObject, float TimePassed){
    std::pair<float, float> Movement = CurrentObject -> getComponent<RigidBody>().speed*TimePassed;
    CurrentObject -> getComponent<Collider>().calculateMassCentre().crs = CurrentObject -> getComponent<Collider>().calculateMassCentre().crs + Movement;
    for (int j = 0; j < CurrentObject -> getComponent<Collider>().dotsList.size(); j++) {
        CurrentObject -> getComponent<Collider>().dotsList[j].crs = CurrentObject -> getComponent<Collider>().dotsList[j].crs + Movement;
    }
};

void MoveColliders(std::vector<GameObject*> objects){
    float TimePassed = Resources::getInstance().CurrentFrameTime - Resources::getInstance().LastFrameTime;
    for (int i = 0; i < objects.size(); i++){
        MoveObject(objects[i], TimePassed);
    }
}

bool TheyCollided(GameObject* object1, GameObject* object2){
    float x0, y0, x1, y1, x, y, norm, coordinate, a1, b1, a2, b2, c2;
    float max = -1*std::numeric_limits<float>::max(), min = std::numeric_limits<float>::max();
    //Checking for one object
    for (int i = 0; i < object1 -> getComponent<Collider>().dotsList.size(); i++){
        if (i == object1 -> getComponent<Collider>().dotsList.size() - 1){
            x1 = getX(object1 -> getComponent<Collider>().dotsList[0].crs);
            y1 = getY(object1 -> getComponent<Collider>().dotsList[0].crs);
        }
        else{
            x1 = getX(object1 -> getComponent<Collider>().dotsList[i + 1].crs);
            y1 = getY(object1 -> getComponent<Collider>().dotsList[i + 1].crs);
        }
        x0 = getX(object1 -> getComponent<Collider>().dotsList[i].crs);
        y0 = getY(object1 -> getComponent<Collider>().dotsList[i].crs);
        norm = std::sqrt(std::pow(x1 - x0, 2) + std::pow(y1 - y0, 2));
        std::pair<float, float> mainRail = std::make_pair((x1 - x0)/norm, (y1 - y0)/norm);
        std::pair<float, float> sideRail = std::make_pair((y1 - y0)/norm, (x0 - x1)/norm);
        a1 = getY(sideRail);
        b1 = -1*getX(sideRail); //one line defined
        a2 = getY(mainRail);
        b2 = -1*getX(mainRail);
        for (int j = 0; j < object1 -> getComponent<Collider>().dotsList.size(); j++){
            x = getX(object1 -> getComponent<Collider>().dotsList[j].crs);
            y = getY(object1 -> getComponent<Collider>().dotsList[j].crs);
            c2 = a2*x + b2*y; //second line defined
            y = c2*a1/(b2*a1 - b1*a2); //cross found
            x = -1*b1*y/a1;
            if (getY(sideRail) != 0) coordinate = y/getY(sideRail);
            else coordinate = x/getX(sideRail);
            if (coordinate < min) min = coordinate;
            if (coordinate > max) max = coordinate;
        }
        std::pair<float, float> selfWidth = std::make_pair(min, max);
        max = -1*std::numeric_limits<float>::max();
        min = std::numeric_limits<float>::max();
        for (int j = 0; j < object2 -> getComponent<Collider>().dotsList.size(); j++){
            x = getX(object2 -> getComponent<Collider>().dotsList[j].crs);
            y = getY(object2 -> getComponent<Collider>().dotsList[j].crs);
            c2 = a2*x + b2*y; //second line defined
            y = c2*a1/(b2*a1 - b1*a2);
            x = -1*b1*y/a1;
            if (getY(sideRail) != 0) coordinate = y/getY(sideRail);
            else coordinate = x/getX(sideRail);
            if (coordinate < min) min = coordinate;
            if (coordinate > max) max = coordinate;
        }
        std::pair<float, float> overWidth = std::make_pair(min, max);
        if (getX(overWidth) > getY(selfWidth) or getY(overWidth) < getX(selfWidth)) return false;
    }
    //and for another
    for (int i = 0; i < object2 -> getComponent<Collider>().dotsList.size(); i++){
        max = -1*std::numeric_limits<float>::max();
        min = std::numeric_limits<float>::max();
        if (i == object2 -> getComponent<Collider>().dotsList.size() - 1){
            x1 = getX(object2 -> getComponent<Collider>().dotsList[0].crs);
            y1 = getY(object2 -> getComponent<Collider>().dotsList[0].crs);
        }
        else{
            x1 = getX(object2 -> getComponent<Collider>().dotsList[i + 1].crs);
            y1 = getY(object2 -> getComponent<Collider>().dotsList[i + 1].crs);
        }
        x0 = getX(object2 -> getComponent<Collider>().dotsList[i].crs);
        y0 = getY(object2 -> getComponent<Collider>().dotsList[i].crs);
        norm = std::sqrt(std::pow(x1 - x0, 2) + std::pow(y1 - y0, 2));
        std::pair<float, float> mainRail = std::make_pair((x1 - x0)/norm, (y1 - y0)/norm);
        std::pair<float, float> sideRail = std::make_pair((y1 - y0)/norm, (x0 - x1)/norm);
        a1 = getY(sideRail);
        b1 = -1*getX(sideRail); //one line defined
        a2 = getY(mainRail);
        b2 = -1*getX(mainRail);
        for (int j = 0; j < object2 -> getComponent<Collider>().dotsList.size(); j++){
            x = getX(object2 -> getComponent<Collider>().dotsList[j].crs);
            y = getY(object2 -> getComponent<Collider>().dotsList[j].crs);
            c2 = a2*x + b2*y; //second line defined
            y = c2*a1/(b2*a1 - b1*a2); //cross found
            x = -1*b1*y/a1;
            if (getY(sideRail) != 0) coordinate = y/getY(sideRail);
            else coordinate = x/getX(sideRail);
            if (coordinate < min) min = coordinate;
            if (coordinate > max) max = coordinate;
        }
        std::pair<float, float> selfWidth = std::make_pair(min, max);
        max = -1*std::numeric_limits<float>::max();
        min = std::numeric_limits<float>::max();
        for (int j = 0; j < object1 -> getComponent<Collider>().dotsList.size(); j++){
            x = getX(object1 -> getComponent<Collider>().dotsList[j].crs);
            y = getY(object1 -> getComponent<Collider>().dotsList[j].crs);
            c2 = a2*x + b2*y; //second line defined
            y = c2*a1/(b2*a1 - b1*a2);
            x = -1*b1*y/a1;
            if (getY(sideRail) != 0) coordinate = y/getY(sideRail);
            else coordinate = x/getX(sideRail);
            if (coordinate < min) min = coordinate;
            if (coordinate > max) max = coordinate;
        }
        std::pair<float, float> overWidth = std::make_pair(min, max);
        if (getX(overWidth) > getY(selfWidth) or getY(overWidth) < getX(selfWidth)) return false;
    }
    return true;
}

void ElasticCollision(GameObject* Object1, GameObject* Object2){
    std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis = FindNewBasisForCollision(Object1, Object2);
    Object1 -> getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(Object1 -> getComponent<RigidBody>().speed, NewBasis);
    Object2 -> getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(Object2 -> getComponent<RigidBody>().speed, NewBasis);
    float Vx1 = std::get<0>(Object1 -> getComponent<RigidBody>().speed);
    float Vy1 = std::get<1>(Object1 -> getComponent<RigidBody>().speed);
    float m1 = Object1 -> getComponent<RigidBody>().mass;
    float Vx2 = std::get<0>(Object2 -> getComponent<RigidBody>().speed);
    float Vy2 = std::get<1>(Object2 -> getComponent<RigidBody>().speed);
    float m2 = Object2 -> getComponent<RigidBody>().mass;
    float P0 = Vx1*m1 + Vx2*m2;
    double E0 = m1*std::pow(Vx1, 2) + m2*std::pow(Vx2, 2);
    std::pair<float, float> newObjectsXSpeeds = solveEqulationSystem(P0, E0, m1, m2, Vx2, Vx1);
    Vx1 = std::get<0>(newObjectsXSpeeds);
    Vx2 = std::get<1>(newObjectsXSpeeds);
    std::pair<std::pair<float, float>, std::pair<float, float>> oldBasis = findMainBasisCoords(NewBasis);
    Object1 -> getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(std::make_pair(Vx1, Vy1), oldBasis);
    Object2 -> getComponent<RigidBody>().speed = FindVectorCoordinatesInNewBasis(std::make_pair(Vx2, Vy2), oldBasis);
};

void SolveCollision(GameObject* object1, GameObject* object2){
    ElasticCollision(object1, object2);
    if (object1 -> getComponent<RigidBody>().unmovable) object1 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
    if (object2 -> getComponent<RigidBody>().unmovable) object2 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
}

void CheckCollisions(const std::vector<GameObject*> movableObjects){
    for (int i = 0; i < movableObjects.size(); i++){
        for (int j = i; j < movableObjects.size(); j++){
            if (j != i and (movableObjects[j]->getComponent<Collider>().cellRadius +
                            movableObjects[j]->getComponent<Collider>().cellRadius >
                            movableObjects[i]->getComponent<Collider>().calculateMassCentre() -
                            movableObjects[j]->getComponent<Collider>().calculateMassCentre())){
                if (TheyCollided(movableObjects[i], movableObjects[j])){
                    SolveCollision(movableObjects[i], movableObjects[j]);
                }
            }
        }
    }
}

void Physics(){
    while (Window::getWindow().isOpen()) {
        std::vector<GameObject*> movableObjects;
        for (int i = 0; i < Resources::getInstance().Objects.size(); i++) {
            if (IsIn<Collider>(Resources::getInstance().Objects[i])) {
                movableObjects.push_back(&Resources::getInstance().Objects[i]);
            }
        }
        Resources::getInstance().LastFrameTime = Resources::getInstance().CurrentFrameTime;
        Resources::getInstance().CurrentFrameTime = Resources::getInstance().Timer.getElapsedTime().asSeconds();
        CheckCollisions(movableObjects);
        //CheckForces(movableObjects);
        MoveColliders(movableObjects);
    }
}

