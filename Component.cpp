//
// Created by ruby on 23.03.18.
//
#include <iostream>
#include <map>
#include <vector>



class abstractComponent{
public:
    virtual void init() = 0;
    virtual ~abstractComponent(){}
};

class Component : abstractComponent{
public:
    virtual void init(){}
};

class Decorator : public abstractComponent{
    abstractComponent *component;
public:Decorator(abstractComponent * component1){
        component = component1;
    }

    void init(){
        component -> init();
    }
};



class RigidBody : Decorator{
    public:
    std::map< int, int> speed;
    RigidBody(abstractComponent* component1, int V_X, int V_Y) : Decorator(component1){speed.insert(std::make_pair(V_X, V_Y));}

    void init(){
        Decorator::init();
        }
};

class DrawMe : Decorator{

//FIXME

    void init(){
        Decorator::init();
    }
};

class Collider : Decorator{

    //FIXME

    bool Detect(float dotX, float dotY, float X0, float Y0, float X1, float Y1){
        float d = (dotX - X0) * (Y1 - Y0) - (dotY - Y0) * (X1 - X0);
        return d > 0;
    }

    void init(){
        Decorator::init();
    }
};

class components{
    std::vector<Component> components_list;

public:
    void addComponent(Component comp){
        list.push_back(comp);

    };
};

