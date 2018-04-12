//
// Created by ruby on 22.03.18.
//

#include "allLibrares.h"
#include "WorkWithPairs.h"
#include "Dot.h"
#include "Components.h"
#include "GameObject.h"
#include "IsIn.h"
#include "resources.h"
#include "Extractors.h"
#include "AnaliticGeometry.h"
#include "Physics.h"
#include "Game.h"

int main(){

    GameObject obj;
    GameObject obj2;

    obj.addComponent<Script>();
    obj2.addComponent<specialScript>();

    obj.getComponent<Script>().update();
    obj2.getComponent<specialScript>().update();




    return 0;
}
