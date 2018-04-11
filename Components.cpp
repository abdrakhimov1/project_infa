//
// Created by ruby on 05.04.18.
//
#include <vector>
#include <typeinfo>
#include <iostream>
#include "Dot.h"
#include "Components.h"

AbstractComponent::~AbstractComponent() {}

RigidBody::RigidBody() {typeID = (char*) typeid(*this).name();}

RigidBody::~RigidBody() {}

void RigidBody::make() {}

Collider::Collider() {typeID = (char*) typeid(*this).name();}

Collider::~Collider() {}

void Collider::make() {}

void Collider::Add_dot(Dot dot, std::vector <Dot> dots_list){
    dots_list.push_back(dot);
}
/*
class AbstractComponent{
public:
    virtual ~AbstractComponent(){}
    virtual void make() = 0;
    const char* typeID;
};


class RigidBody : public AbstractComponent{
public:
    RigidBody(){typeID = (char*) typeid(*this).name();}
    ~RigidBody(){}
    void make(){}
    std::pair<float, float> speed;
    float mass;
    int a = 12;
};

class Collider : public AbstractComponent{
public:
    Collider(){typeID = (char*) typeid(*this).name();}
    ~Collider(){}
    void make(){}
    std::vector<Dot> dotsList;
    Dot massCentre;
    void Add_dot(Dot dot, std::vector<Dot> dots_list){
        dots_list.push_back(dot);
    }
    int k = 11;
};
*/