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
    std::cout << "Better check" << std::endl;
    Dot dot1(500, 200);
    Dot dot2(300, 160);
    Dot dot3(80, 600);
    Dot dot4(200, 200);
    Dot dot5(120, 120);
    Dot dot6(120, 240);
    float x = 2.0;
    std::pair<float, float> speed1 = std::make_pair(x, x);
    std::pair<float, float> speed2 = std::make_pair(-1*x, -1*x);
    float mass = 200;
    std::cout << "That's not so bad" << std::endl;

    createTriangle(dot1, dot2, dot3, speed2, mass, "test_texture.jpg");
    createTriangle(dot4, dot5, dot6, speed1, mass, "test_texture.jpg");
    std::cout << Resources::getInstance().Objects.size() << std::endl;

    std::thread drawing(drawLines);
    std::thread physics(MoveColliders);

    drawing.join();
    physics.join();

    return 0;
}
