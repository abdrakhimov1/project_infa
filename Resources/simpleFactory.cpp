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