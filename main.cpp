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
    object.addComponent<Collider>();



    object.getComponent<RigidBody>().a = 10;
    int b = object.getComponent<RigidBody>().a;
    int c = object.getComponent<Collider>().k;
    std::cout << c << std::endl;
    std::cout << b << std::endl;



    return 0;
}
