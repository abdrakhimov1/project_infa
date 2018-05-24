//
// Created by ruby on 24.05.18.
//
#include <string>
#include <iostream>
#include "../../Resources/GameObject.h"
#include "../../Resources/resources.h"
#include "../../Resources/Components.h"
#include "../../Staff/allLibraries.h"

#ifndef PROJECT_USERAPI_H
#define PROJECT_USERAPI_H


class specialScript{
public:
    specialScript();
    ~specialScript() {};

    void update(){

    }

};

class Factory : public specialScript{
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


#endif //PROJECT_USERAPI_H
