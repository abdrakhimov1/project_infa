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
    //std::cout << "a"  << std::endl;

    object.getComponent<RigidBody>();
    //int b = object.getComponent<RigidBody>().a;



    return 0;
}
