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



class Speed: Decorator{
    public:
    std::map< int, int> speed;
    Speed(abstractComponent* component1, int V_X, int V_Y) : Decorator(component1){speed.insert(std::make_pair(V_X, V_Y));}

    void init(){
        Decorator::init();

        std::cout << "Speed addded. \n" << std::endl;
        }
};

class components{
    std::vector<Component> list;

public:
    void addComponent(Component comp){
        list.push_back(comp);

    };
};

