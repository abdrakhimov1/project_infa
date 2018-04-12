//
// Created by ruby on 12.04.18.
//

#include "allLibrares.h"
#include "Components.h"

#ifndef PROJECT_INFA_GAME_H
#define PROJECT_INFA_GAME_H

class specialScript : public Script{
public:
    specialScript();
    ~specialScript() {};
    void make() {};

    void update(){
        std::cout << "specialObject" << std::endl;
    }
};

#endif //PROJECT_INFA_GAME_H
