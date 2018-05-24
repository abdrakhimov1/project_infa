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
#include "Physics/Physics2.0.h"
#include "Drawing/drawAll.h"
#include "Resources/simpleFactory.h"
#include "Drawing/drawLines.h"
#include "Logic/UserAPI/UserAPI.h"



int main(){
    Dot dot1(500, 200), dot2(300, 560), dot3(480, 600);
    Dot dot4(200, 200), dot5(120, 120), dot6(130, 240);
    Dot dot7(1000, 200), dot8(950, 350), dot9(960, 125);
    float x = 40.0;
    std::pair<float, float> speed1 = std::make_pair(x, x+2);
    std::pair<float, float> speed2 = std::make_pair(-1*x, -1*x);
    float mass = 200;

    createTriangle(dot1, dot2, dot3, speed2, mass, "test_texture.jpg");
    createTriangle(dot4, dot5, dot6, speed1, mass, "test_texture.jpg");
    createTriangle(dot7, dot8, dot9, std::make_pair(-1*x, x), 10*mass, "test_texture.jpg");
    //createBorder();

    std::thread drawing(drawLines);
    std::thread physics(Physics);

    drawing.join();
    physics.join();

    return 0;
}
