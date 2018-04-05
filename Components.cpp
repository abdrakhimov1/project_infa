//
// Created by ruby on 05.04.18.
//
#include <vector>
#include <typeinfo>
#include <iostream>

class AbstractComponent{
public:
    virtual ~AbstractComponent(){}
    virtual void make() = 0;

    const char* typeID = typeid(*this).name();
};


class RigidBody : public AbstractComponent{
public:
    RigidBody(){}
    ~RigidBody(){}
    std::pair<float, float> speed;
    int a = 2;
    void make(){}
};

