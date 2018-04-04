//
// Created by ruby on 22.03.18.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>
#include "GameObject.cpp"
#include "resourses.cpp"
#include "Physics.cpp"

int main(){
    GameObjectWithRigidBody *objwithspeed = new GameObjectWithRigidBody(new SimpleGameObject);
    objwithspeed -> init();
    objwithspeed -> speed = std::make_pair(4, 3);

    GameObjectWithCollider *objectWithCollider = new GameObjectWithCollider(new SimpleGameObject);

    return 0;
}
