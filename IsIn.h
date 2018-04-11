//
// Created by fantom on 06.04.18.
//

#include "GameObject.h"
#include "allLibrares.h"

#ifndef PROJECT_INFA_ISIN_H
#define PROJECT_INFA_ISIN_H

template <typename T>
bool IsIn(GameObject object){
    for(int i =0; i < object.componentsList.size(); i++){
        if(strcmp(object.componentsList[i] -> typeID, typeid(T).name()) == 0) {
            return true;
        }
    }
    return false;
}

#endif //PROJECT_INFA_ISIN_H
