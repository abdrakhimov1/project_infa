//
// Created by ruby on 22.03.18.
//

//#include "Component.cpp"
#include <vector>
#include <iostream>
#include <utility>
#include "Component.cpp"

class abstractGameObject{
    components* c = new components;
public:
    virtual void init() = 0;
        virtual ~abstractGameObject(){}

        std::pair<float, float> CenterCoordinates;

};


class GameObject : public abstractGameObject{
public:
    virtual void init(){

    }
};

int main(){
    return 0;
}

