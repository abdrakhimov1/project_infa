//
// Created by ruby on 22.03.18.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include "GameObject.cpp"
#include "Component.cpp"
#include "resourses.cpp"
#include "Physics.cpp"

int main(){
    GameObject gameobject;
    Final Try(new RigidBody(new Component(gameobject)));
    return 0;
}
