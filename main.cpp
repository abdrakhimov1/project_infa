//
// Created by ruby on 22.03.18.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include "GameObject.cpp"

//#include "resourses.cpp"
//#include "Physics.cpp"




int main(){

    GameObject object;

    object.addComponent<RigidBody>();


    object.getComponent<RigidBody>().a = 15;
    int b = object.getComponent<RigidBody>().a;
    std::cout << b << std::endl;
    std::cout << typeid(object.getComponent<RigidBody>().a).name() << std::endl;



    return 0;
}
