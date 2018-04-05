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
    char* typeID;
};


class RigidBody : public AbstractComponent{
public:
    RigidBody(){}
    ~RigidBody(){}
    std::pair<float, float> speed;
    void make(){}
    char *typeID = (char*) typeid(*this).name();
    int a = 12;
};

