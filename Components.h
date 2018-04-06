//
// Created by fantom on 06.04.18.
//

#include <vector>
#include <typeinfo>
#include <iostream>
#include "Dot.h"

#ifndef PROJECT_INFA_COMPONENTS_H
#define PROJECT_INFA_COMPONENTS_H


class AbstractComponent{
public:
    virtual ~AbstractComponent();
    virtual void make() = 0;
    const char* typeID;
};


class RigidBody : public AbstractComponent{
public:
    RigidBody();
    ~RigidBody();
    void make();
    std::pair<float, float> speed;
    float mass;
    int a = 12;
};

class Collider : public AbstractComponent{
public:
    Collider();
    ~Collider();
    void make();
    std::vector<Dot> dotsList;
    Dot massCentre;
    void Add_dot(Dot dot, std::vector<Dot> dots_list);
    int k = 11;
};

#endif //PROJECT_INFA_COMPONENTS_H
