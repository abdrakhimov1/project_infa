//
// Created by fantom on 05.05.18.
//

#include "simpleFactory.h"

void createTriangle(Dot dot1, Dot dot2, Dot dot3, std::pair<float, float> speed, float mass, std::string texture_name){
    GameObject* object = new GameObject;
    object -> addComponent<Collider>();
    object -> getComponent<Collider>().Add_dot(dot1);
    object -> getComponent<Collider>().Add_dot(dot2);
    object -> getComponent<Collider>().Add_dot(dot3);
    object -> getComponent<Collider>().calculateCellRadius();
    object -> addComponent<RigidBody>();
    object -> getComponent<RigidBody>().mass = mass;
    object -> getComponent<RigidBody>().speed = speed;
    object -> addComponent<DrawMe>();
    object -> getComponent<DrawMe>().texture_name = texture_name;
    Resources::getInstance().Objects.push_back(*object);
}

void createBorder() {
    GameObject* object1 = new GameObject;
    Dot dot1(0, 0), dot2(0, 960), dot3 (5, 960), dot4(5, 0);
    object1 -> addComponent<Collider>();
    object1 -> getComponent<Collider>().Add_dot(dot1);
    object1 -> getComponent<Collider>().Add_dot(dot2);
    object1 -> getComponent<Collider>().Add_dot(dot3);
    object1 -> getComponent<Collider>().Add_dot(dot4);
    object1 -> getComponent<Collider>().calculateCellRadius();
    object1 -> addComponent<RigidBody>();
    object1 -> getComponent<RigidBody>().mass = std::numeric_limits<float>::max();
    object1 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
    object1 -> getComponent<RigidBody>().unmovable = true;
    Resources::getInstance().Objects.push_back(*object1);
    GameObject* object2 = new GameObject;
    object2 -> addComponent<Collider>();
    dot1.crs = std::make_pair(5, 0);
    dot2.crs = std::make_pair(5, 5);
    dot3.crs = std::make_pair(1275, 5);
    dot4.crs = std::make_pair(1275, 0);
    object2 -> getComponent<Collider>().Add_dot(dot1);
    object2 -> getComponent<Collider>().Add_dot(dot2);
    object2 -> getComponent<Collider>().Add_dot(dot3);
    object2 -> getComponent<Collider>().Add_dot(dot4);
    object2 -> getComponent<Collider>().calculateCellRadius();
    object2 -> addComponent<RigidBody>();
    object2 -> getComponent<RigidBody>().mass = std::numeric_limits<float>::max();
    object2 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
    object2 -> getComponent<RigidBody>().unmovable = true;
    Resources::getInstance().Objects.push_back(*object2);
    GameObject* object3 = new GameObject;
    object3 -> addComponent<Collider>();
    dot1.crs = std::make_pair(1275, 0);
    dot2.crs = std::make_pair(1275, 960);
    dot3.crs = std::make_pair(1280, 960);
    dot4.crs = std::make_pair(1280, 0);
    object3 -> getComponent<Collider>().Add_dot(dot1);
    object3 -> getComponent<Collider>().Add_dot(dot2);
    object3 -> getComponent<Collider>().Add_dot(dot3);
    object3 -> getComponent<Collider>().Add_dot(dot4);
    object3 -> getComponent<Collider>().calculateCellRadius();
    object3 -> addComponent<RigidBody>();
    object3 -> getComponent<RigidBody>().mass = std::numeric_limits<float>::max();
    object3 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
    object3 -> getComponent<RigidBody>().unmovable = true;
    Resources::getInstance().Objects.push_back(*object3);
    GameObject* object4 = new GameObject;
    object4 -> addComponent<Collider>();
    dot1.crs = std::make_pair(5, 955);
    dot2.crs = std::make_pair(5, 960);
    dot3.crs = std::make_pair(1275, 960);
    dot4.crs = std::make_pair(1275, 955);
    object4 -> getComponent<Collider>().Add_dot(dot1);
    object4 -> getComponent<Collider>().Add_dot(dot2);
    object4 -> getComponent<Collider>().Add_dot(dot3);
    object4 -> getComponent<Collider>().Add_dot(dot4);
    object4 -> getComponent<Collider>().calculateCellRadius();
    object4 -> addComponent<RigidBody>();
    object4 -> getComponent<RigidBody>().mass = std::numeric_limits<float>::max();
    object4 -> getComponent<RigidBody>().speed = std::make_pair(0, 0);
    object4 -> getComponent<RigidBody>().unmovable = true;
    Resources::getInstance().Objects.push_back(*object4);
}

void createSquare(Dot dot1, Dot dot2, Dot dot3, Dot dot4, std::pair<float, float> speed, float mass, std::string texture_name, bool unmovable){
    GameObject* square = new GameObject;
    square -> addComponent<Collider>();
    square -> getComponent<Collider>().Add_dot(dot1);
    square -> getComponent<Collider>().Add_dot(dot2);
    square -> getComponent<Collider>().Add_dot(dot3);
    square -> getComponent<Collider>().Add_dot(dot4);
    square -> getComponent<Collider>().calculateCellRadius();
    square -> addComponent<RigidBody>();
    square -> getComponent<RigidBody>().mass = mass;
    square -> getComponent<RigidBody>().speed = speed;
    square -> getComponent<RigidBody>().unmovable = unmovable;
    square -> addComponent<DrawMe>();
    square -> getComponent<DrawMe>().texture_name = texture_name;
    Resources::getInstance().Objects.push_back(*square);
}