//
// Created by ruby on 22.03.18.
//

#include "allLibraries.h"
#include "WorkWithPairs.h"
#include "Dot.h"
#include "Components.h"
#include "GameObject.h"
#include "IsIn.h"
#include "resources.h"
#include "Extractors.h"
#include "Sprite.h"
#include "AnaliticGeometry.h"
#include "Physics.h"
#include "drawAll.h"
#include "simpleFactory.h"
#include "drawLines.h"
//#include "Game.h"


int main(){
/*
    GameObject obj;
    GameObject obj2;

    obj.addComponent<Script>();
    obj2.addComponent<specialScript>();
    obj.addComponent<Factory>();

    obj.getComponent<Script>().update();
    obj2.getComponent<specialScript>().update();


    obj.getComponent<Factory>().update();
    obj.getComponent<Factory>().createPlane();

    Factory::createPlane();

    Factory::addRigidBody(obj, 5, 10);




*/
    Dot dot1(500, 200);
    Dot dot2(300, 560);
    Dot dot3(480, 600);
    Dot dot4(200, 200);
    Dot dot5(120, 120);
    Dot dot6(120, 240);
    float x = 50.0;
    std::pair<float, float> speed1 = std::make_pair(x, x+10);
    std::pair<float, float> speed2 = std::make_pair(-1*x, -1*x);
    float mass = 200;

    createTriangle(dot1, dot2, dot3, speed2, mass, "test_texture.jpg");
    createTriangle(dot4, dot5, dot6, speed1, mass, "test_texture.jpg");
    //createBorder();

    std::cout << TheyCollided(Resources::getInstance().Objects[0], Resources::getInstance().Objects[1]);
    std::cout << TheyCollided(Resources::getInstance().Objects[1], Resources::getInstance().Objects[0]);

    std::thread drawing(drawLines);
    std::thread physics(MoveColliders);

    drawing.join();
    physics.join();

    return 0;
}
