//
// Created by fantom on 06.04.18.
// Modified by verwindle on 07.04.18.; on 10.04.18.; on 17.04.18.
//
#include "allLibraries.h"
#include "Dot.h"
#include "Sprite.h"
#include "Window.h"

#ifndef PROJECT_INFA_COMPONENTS_H
#define PROJECT_INFA_COMPONENTS_H

class GameObject;

class AbstractComponent{
public:
    GameObject*  object;
    virtual ~AbstractComponent();
    virtual void make() = 0;
    const char* typeID;
};


class RigidBody : public AbstractComponent{
public:
    RigidBody(GameObject& object);
    ~RigidBody();
    void make();
    std::pair<float, float> speed;
    float mass;
    float momentOfInertion;
};

class DrawMe : public AbstractComponent{
public:
    DrawMe(GameObject& object, Sprite sprite);

    Dot setSpriteCentre();

    std::vector<Dot> setSpriteCoordinates();

    ~DrawMe();
};

class Collider : public AbstractComponent{
public:
    Collider(GameObject& object);
    ~Collider();
    void make();
    std::vector<Dot> dotsList;
    Dot calculateMassCentre();
    void Add_dot(Dot dot);
    float cellRadius;
};

#endif //PROJECT_INFA_COMPONENTS_H
