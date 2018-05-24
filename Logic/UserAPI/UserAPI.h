//
// Created by ruby on 24.05.18.
//
#include <string>
#include <iostream>
#include "../../Resources/GameObject.h"
#include "../../Resources/Dot.h"
#include "../../Resources/resources.h"
#include "../../Resources/Components.h"
#include "../../Staff/allLibraries.h"

#ifndef PROJECT_USERAPI_H
#define PROJECT_USERAPI_H


class specialScript{
public:
    specialScript();
    ~specialScript() {};
    void update(){}

};

class Factory : public specialScript{
public:

    Factory();

    static GameObject createPlane(){

        GameObject plane;
        Resources::getInstance().addObject(plane);
        return plane;
    }

    static GameObject createBall(){
        GameObject ball;
        Resources::getInstance().addObject(ball);
        return ball;
    }

    static GameObject createTriangle(Dot dot1, Dot dot2, Dot dot3, std::pair<float, float> speed, float mass, std::string texture_name){
        GameObject triangle;
        triangle.addComponent<Collider>();
        triangle.getComponent<Collider>().Add_dot(dot1);
        triangle.getComponent<Collider>().Add_dot(dot2);
        triangle.getComponent<Collider>().Add_dot(dot3);
        triangle.getComponent<Collider>().calculateCellRadius();
        triangle.addComponent<RigidBody>();
        triangle.getComponent<RigidBody>().mass = mass;
        triangle.getComponent<RigidBody>().speed = speed;
        triangle.addComponent<DrawMe>();
        triangle.getComponent<DrawMe>().texture_name = texture_name;
        Resources::getInstance().addObject(triangle);
        return triangle;
    }

    static void addRigidBody(GameObject object, float speedX, float speedY){
        object.addComponent<RigidBody>();
        object.getComponent<RigidBody>().speed.first = speedX;
        object.getComponent<RigidBody>().speed.first = speedY;
    }

    static void addCollider(GameObject object, std::vector<Dot> colliderDotsList){
        object.addComponent<Collider>();
        object.getComponent<Collider>().dotsList = colliderDotsList;
    }

    static void addDrawMe(GameObject object, std::string setting_texture_name){
        object.addComponent<DrawMe>();
        object.getComponent<DrawMe>().texture_name = setting_texture_name;
    }

    void update(){
        std::cout << "Factory built" << std::endl;
    }
};


#endif //PROJECT_USERAPI_H
