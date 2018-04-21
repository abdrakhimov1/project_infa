//
// Created by ruby on 12.04.18.
//

#include "allLibrares.h"
#include "Components.h"
#include "resources.h"



#ifndef PROJECT_INFA_GAME_H
#define PROJECT_INFA_GAME_H

class specialScript : public Script{
public:
    specialScript();
    ~specialScript() {};

    void update(){
        std::cout << "specialObject" << std::endl;
    }

};

class Factory : public Script{
public:
    Factory();

    void createPlane(){
        GameObject plane;
        Resources::getInstance().addObject(plane);
        std::cout << "Plane built" << std::endl;

    };

    void update(){
        std::cout << "Factory built" << std::endl;
    }


};

#endif //PROJECT_INFA_GAME_H
