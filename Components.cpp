//
// Created by ruby on 05.04.18.
//
#include "Components.h"
#include "resources.h"
#include "AnaliticGeometry.h"

AbstractComponent::~AbstractComponent() {}

RigidBody::RigidBody(GameObject& object)
{
    typeID = (char*) typeid(*this).name();
    AbstractComponent::object = &object;
}

RigidBody::~RigidBody() {}

void RigidBody::make() {}

DrawMe::DrawMe(GameObject& object) {
    typeID = (char*) typeid(*this).name();
    AbstractComponent::object = &object;
}

void DrawMe::make() {}

Dot DrawMe::setSpriteCentre() {
    return object -> getComponent<Collider>().calculateMassCentre();
}

std::vector<Dot> DrawMe::setSpriteCoordinates() {
    return object -> getComponent<Collider>().dotsList;
}

DrawMe::~DrawMe() {
    //I donno what to do here
}

void DrawMe::Draw() {
    Sprite sprite(*object, texture_name);
    sprite.draw();
}

Collider::Collider(GameObject& object) {
    typeID = (char*) typeid(*this).name();
    AbstractComponent::object = &object;
}

Collider::~Collider() {}

void Collider::make() {}

Dot Collider::calculateMassCentre() {
    Dot centre = Dot(0, 0);
    std::vector<Dot> dots = dotsList;

    float number_of_dots = sizeof(dots);
    for (auto dot : dots) {
        centre.crs = centre.crs + dot.crs;
    }
    centre.crs = centre.crs/number_of_dots;
    return centre;
}

void Collider::Add_dot(Dot dot){
    this -> dotsList.push_back(dot);
}

void Collider::calculateCellRadius() {
    float maximumDistance = 0;
    float tmp = 0;
    for (int i = 0; i < dotsList.size(); i++){
        tmp = this -> calculateMassCentre() - dotsList[i];
        if (tmp > maximumDistance) maximumDistance = tmp;
    }
    cellRadius = maximumDistance + 1;
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