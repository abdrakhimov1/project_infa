//
// Created by fantom on 06.04.18.
// Modified by verwindle on 07.04.18.; on 10.04.18.; on 17.04.18.
//
#include "../Staff/allLibraries.h"
#include "Dot.h"
#include "../Drawing/Sprite.h"
#include "../Drawing/Window.h"

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
    RigidBody(GameObject* object);
    ~RigidBody();
    void make();
    std::pair<float, float> speed;
    float mass;
    float momentOfInertion;
    bool unmovable;
};

class DrawMe : public AbstractComponent{
public:
    DrawMe(GameObject* object);
    Dot setSpriteCentre();
    std::vector<Dot> setSpriteCoordinates();
    void make();
    void Draw();
    std::string texture_name;

    ~DrawMe();
};

class Collider : public AbstractComponent{
public:
    Collider(GameObject* object);
    ~Collider();
    void make();
    std::vector<Dot> dotsList;
    Dot calculateMassCentre();
    void Add_dot(Dot dot);
    float cellRadius;
    void calculateCellRadius();
};

#endif //PROJECT_INFA_COMPONENTS_H
