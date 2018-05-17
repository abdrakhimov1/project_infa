//
// Created by fantom on 06.04.18.
//

#include "Dot.h"

Dot::Dot(float x, float y){
    crs = std::make_pair(x, y);
}

Dot::Dot(){
    crs = std::make_pair(0, 0);
}