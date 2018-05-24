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

    static GameObject createPlane(Dot dot1, std::pair<float, float> speed, float mass, std::string texture_name){
        GameObject plane;
        plane.addComponent<Collider>();
        plane.getComponent<Collider>().Add_dot(dot1);
        plane.getComponent<Collider>().calculateCellRadius();
        plane.addComponent<RigidBody>();
        plane.getComponent<RigidBody>().mass = mass;
        plane.getComponent<RigidBody>().speed = speed;
        plane.addComponent<DrawMe>();
        plane.getComponent<DrawMe>().texture_name = texture_name;
        Resources::getInstance().addObject(plane);
        return plane;
    }

    static GameObject createBall(Dot dot1, std::pair<float, float> speed, float mass, std::string texture_name){
        GameObject ball;
        ball.addComponent<Collider>();
        ball.getComponent<Collider>().Add_dot(dot1);
        ball.getComponent<Collider>().calculateCellRadius();
        ball.addComponent<RigidBody>();
        ball.getComponent<RigidBody>().mass = mass;
        ball.getComponent<RigidBody>().speed = speed;
        ball.addComponent<DrawMe>();
        ball.getComponent<DrawMe>().texture_name = texture_name;
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

    static GameObject createSquare(Dot dot1, Dot dot2, Dot dot3, Dot dot4, std::pair<float, float> speed, float mass, std::string texture_name){
        GameObject square;
        square.addComponent<Collider>();
        square.getComponent<Collider>().Add_dot(dot1);
        square.getComponent<Collider>().Add_dot(dot2);
        square.getComponent<Collider>().Add_dot(dot3);
        square.getComponent<Collider>().Add_dot(dot4);
        square.getComponent<Collider>().calculateCellRadius();
        square.addComponent<RigidBody>();
        square.getComponent<RigidBody>().mass = mass;
        square.getComponent<RigidBody>().speed = speed;
        square.addComponent<DrawMe>();
        square.getComponent<DrawMe>().texture_name = texture_name;
        Resources::getInstance().addObject(square);
        return square;
    }

    static void createBorder() {
        GameObject* object1 = new GameObject;
        Dot dot1(0, 0), dot2(0, 960), dot3 (1, 960), dot4(1, 0);
        object1 -> addComponent<Collider>();
        object1 -> getComponent<Collider>().Add_dot(dot1);
        object1 -> getComponent<Collider>().Add_dot(dot2);
        object1 -> getComponent<Collider>().Add_dot(dot3);
        object1 -> getComponent<Collider>().Add_dot(dot4);
        object1 -> getComponent<Collider>().calculateCellRadius();
        object1 -> addComponent<RigidBody>();
        object1 -> getComponent<RigidBody>().mass = 1;
        object1 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
        object1 -> getComponent<RigidBody>().unmovable = true;
        Resources::getInstance().Objects.push_back(*object1);
        GameObject* object2 = new GameObject;
        object2 -> addComponent<Collider>();
        dot1.crs = std::make_pair(1, 0);
        dot2.crs = std::make_pair(1, 1);
        dot3.crs = std::make_pair(1279, 1);
        dot4.crs = std::make_pair(1279, 0);
        object2 -> getComponent<Collider>().Add_dot(dot1);
        object2 -> getComponent<Collider>().Add_dot(dot2);
        object2 -> getComponent<Collider>().Add_dot(dot3);
        object2 -> getComponent<Collider>().Add_dot(dot4);
        object2 -> getComponent<Collider>().calculateCellRadius();
        object2 -> addComponent<RigidBody>();
        object2 -> getComponent<RigidBody>().mass = 1;
        object2 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
        object2 -> getComponent<RigidBody>().unmovable = true;
        Resources::getInstance().Objects.push_back(*object2);
        GameObject* object3 = new GameObject;
        object3 -> addComponent<Collider>();
        dot1.crs = std::make_pair(1279, 0);
        dot2.crs = std::make_pair(1279, 960);
        dot3.crs = std::make_pair(1280, 960);
        dot4.crs = std::make_pair(1280, 0);
        object3 -> getComponent<Collider>().Add_dot(dot1);
        object3 -> getComponent<Collider>().Add_dot(dot2);
        object3 -> getComponent<Collider>().Add_dot(dot3);
        object3 -> getComponent<Collider>().Add_dot(dot4);
        object3 -> getComponent<Collider>().calculateCellRadius();
        object3 -> addComponent<RigidBody>();
        object3 -> getComponent<RigidBody>().mass = 1;
        object3 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
        object3 -> getComponent<RigidBody>().unmovable = true;
        Resources::getInstance().Objects.push_back(*object3);
        GameObject* object4 = new GameObject;
        object4 -> addComponent<Collider>();
        dot1.crs = std::make_pair(1, 959);
        dot2.crs = std::make_pair(1, 960);
        dot3.crs = std::make_pair(1279, 960);
        dot4.crs = std::make_pair(1279, 959);
        object4 -> getComponent<Collider>().Add_dot(dot1);
        object4 -> getComponent<Collider>().Add_dot(dot2);
        object4 -> getComponent<Collider>().Add_dot(dot3);
        object4 -> getComponent<Collider>().Add_dot(dot4);
        object4 -> getComponent<Collider>().calculateCellRadius();
        object4 -> addComponent<RigidBody>();
        object4 -> getComponent<RigidBody>().mass = 1;
        object4 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
        object4 -> getComponent<RigidBody>().unmovable = true;
        Resources::getInstance().Objects.push_back(*object4);
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
