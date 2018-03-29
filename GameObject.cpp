//
// Created by ruby on 22.03.18.
//

//#include "Component.cpp"
#include <vector>
#include <iostream>
#include "Component.cpp"

class abstractGameObject{
    components* c = new components;
public:
    virtual void init() = 0;
        virtual ~abstractGameObject(){}

        float matrix[2][2];

};


class GameObject : public abstractGameObject{
public:
    virtual void init(){

    }
};

int main(){
    return 0;
}

