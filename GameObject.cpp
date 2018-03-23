//
// Created by ruby on 22.03.18.
//

#include "Component.cpp"

class abstractGameObject{
public:
    virtual void init() = 0;
        virtual ~abstractGameObject(){}
        vector<Component> Components;
        int matrix[3][3];
};


class GameObject : public abstractGameObject{
public:
    virtual void init(){

    }
};

