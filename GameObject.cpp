//
// Created by ruby on 22.03.18.
//

#include <vector>
#include <iostream>

class abstractGameObject{
public:
    virtual void init() = 0;
        virtual ~abstractGameObject(){}
    std::vector<std::string> ComponentsVector;
};


class GameObject : public abstractGameObject{
public:
    virtual void init(){

    }
};


