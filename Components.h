//
// Created by fantom on 06.04.18.
//

#include "Dot.h"
#include "allLibrares.h"
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
    float momentOfInertion;
};

class Collider : public AbstractComponent{
public:
    Collider();
    ~Collider();
    void make();
    std::vector<Dot> dotsList;
    Dot massCentre;
    void Add_dot(Dot dot, std::vector<Dot> dots_list);
    float cellRadius;
};

class Script : public AbstractComponent{
public:
    Script();
    ~Script();
    void make();

    void update(){
        std::cout << "check" << std::endl;
    }
};



#endif //PROJECT_INFA_COMPONENTS_H
