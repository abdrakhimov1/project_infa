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
    const char* typeID;
};


class RigidBody : public AbstractComponent{
public:
    RigidBody(){typeID = (char*) typeid(*this).name();}
    ~RigidBody(){}
    void make(){}
    std::pair<float, float> speed;
    float mass;
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
};



