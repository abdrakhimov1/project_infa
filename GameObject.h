//
// Created by fantom on 06.04.18.
//

#ifndef PROJECT_INFA_GAMEOBJECT_H
#define PROJECT_INFA_GAMEOBJECT_H

#include <vector>
#include "Components.h"
#include <cstring>

class GameObject{
public:
    std::vector<AbstractComponent*> componentsList;

    template <typename T>
    void addComponent(){
        T *prop = new T;
        componentsList.push_back(prop);
    }

    template <typename T>
    T& getComponent(){
        for(int i =0; i < componentsList.size(); i++){
            if(strcmp(componentsList[i] -> typeID, typeid(T).name()) == 0) {
                T *subClass = dynamic_cast<T*>(componentsList[i]);
                return *subClass;
            }
        }
    }
};

#endif //PROJECT_INFA_GAMEOBJECT_H
