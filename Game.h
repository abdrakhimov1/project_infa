//
// Created by ruby on 12.04.18.
//

#include "allLibrares.h"
#include "Components.h"
#include "resources.h"
#include "allLibrares.h"



#ifndef PROJECT_INFA_GAME_H
#define PROJECT_INFA_GAME_H

class specialScript : public Script{
public:
    specialScript();
    ~specialScript() {};

    void update(){

    }

};

class Factory : public Script{
public:
    Factory();

    static GameObject createPlane(){

        GameObject plane;
        Resources::getInstance().addObject(plane);
        return plane;
    };

    void update(){
        std::cout << "Factory built" << std::endl;
    }

    static void addRigidBody(GameObject object, float speedX, float speedY){
        object.addComponent<RigidBody>();
        object.getComponent<RigidBody>().speed.first = speedX;
        object.getComponent<RigidBody>().speed.first = speedY;

    }


};

#endif //PROJECT_INFA_GAME_H
