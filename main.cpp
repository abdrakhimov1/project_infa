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


    abstractGameObject *obj = new GameObjectWithCollider(new GameObjectWithDrawMeFunction( new GameObjectWithRigidBody((new SimpleGameObject))));
    obj->init();

    int s = obj -> b;//В декораторе GameObjectWithDrawFunction есть переменная b.



    return 0;
}
