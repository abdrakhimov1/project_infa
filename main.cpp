//
// Created by ruby on 22.03.18.
//

#include "Staff/allLibraries.h"
#include "Logic/WorkWithPairs.h"
#include "Resources/Dot.h"
#include "Resources/Components.h"
#include "Resources/GameObject.h"
#include "Logic/IsIn.h"
#include "Resources/resources.h"
#include "Logic/Extractors.h"
#include "Drawing/Sprite.h"
#include "Physics/AnaliticGeometry.h"
#include "Physics/Physics.h"
#include "Drawing/drawAll.h"
#include "Resources/simpleFactory.h"
#include "Drawing/drawLines.h"
#include "Logic/UserAPI/UserAPI.h"



int main(){
    Dot dot1(500, 200);
    Dot dot2(300, 560);
    Dot dot3(480, 600);
    Dot dot4(200, 200);
    Dot dot5(120, 120);
    Dot dot6(120, 240);
    float x = 10.0;
    std::pair<float, float> speed1 = std::make_pair(x, x+2);
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
