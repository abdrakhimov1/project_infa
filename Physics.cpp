//
// Created by fantom on 22.03.18.
//

#define resources Resources::getInstance()
#include <cmath>

bool IsIn(std::string Name, std::vector<std::string> NamesVector) {
    bool result = false;
    for (int i = 0; i < NamesVector.size(); i++) {
        if (NamesVector[i] == Name)
            result = true;
    }
    return  result;
};

std::pair<float, float> SummPairs(std::pair<float, float> FirstPair, std::pair<float, float> SecondPair) {
    float TMP1 = std::get<0>(FirstPair) + std::get<0>(SecondPair);
    float TMP2 = std::get<1>(FirstPair) + std::get<1>(SecondPair);
    return std::make_pair(TMP1, TMP2);
};

std::pair<float, float> MultiplyPair(std::pair<float, float> Pair, float Constant) {
    float TMP1 = std::get<0>(Pair)*Constant;
    float TMP2 = std::get<1>(Pair)*Constant;
    return std::make_pair(TMP1, TMP2);
};

std::pair<float, float> ExtractSpeed(GameObject object) {
    std::pair<float, float> speed;
    if (IsIn("RigidBody", object.ComponentsVector)) {
        return object.speed;
    }
    //FIXME - can work with StupidObject only :)
    return std::make_pair(10, 10);
};
//Extract speed from GameObject

std::vector<Dot> ExtractDots(GameObject object){
    if (IsIn("Collider", object.ComponentsVector)){
        return object.dots_list;
    }
    //FIXME - can work with StupidObject only :)
    std::vector<Dot> EmptyAnswer;
    return EmptyAnswer;
};
//Extracts vector of dots from GameObject

void MoveObject(GameObject CurrentObject, float TimePassed){
    std::pair<float, float> CurrentSpeed = ExtractSpeed(CurrentObject);
    std::vector<Dot> DotVector = ExtractDots(CurrentObject);
    for (int j = 0; j < DotVector.size(); j++) {
        std::pair<float, float> CurrentCoordinates = DotVector[j].crs;
        std::pair<float, float> Movement = MultiplyPair(CurrentSpeed, TimePassed);
        std::pair<float, float> NewCoordinates = SummPairs(CurrentCoordinates, Movement);
        DotVector[j].crs = NewCoordinates;
    }
};
//This one moves all dots of one object.

void RotateObject(GameObject object, float TimePassed){
    //FIXME
};
//Rotate object. Now unavailable

void CheckForces(){
    //FIXME
};
//Find all forces, affecting all objects, and changes their speed

bool TheyCollided(GameObject Object1, GameObject Object2){
    bool result;
    //FIXME
};
//Inspect if two given objects have collided

void MoveSpeedToNewCoords(GameObject Object, std::pair<float, float> X, std::pair<float, float> Y){
    float Vx0, Vy0, Vx1, Vy1, x1, y1, x2, y2;
    Vx0 = std::get<0>(Object.speed);
    Vy0 = std::get<1>(Object.speed);
    x1 = std::get<0>(X);
    x2 = std::get<1>(X);
    y1 = std::get<0>(Y);
    y2 = std::get<1>(Y);
    Vy1 = (Vy0*x1 - Vx0*y1)/(x1*y2 - x2*y1);
    Vx1 = Vx0/x1 - Vy1*x2/x1;
    Object.speed = std::make_pair(Vx1, Vy1);
};
//Some technical shit, don't touch it

void GoToNewCoords(GameObject Object1, GameObject Object2){
    std::pair<float, float> FirstCenter = Object1.MassCenter;
    std::pair<float, float> SecondCenter = Object2.MassCenter;
    std::pair<float, float> X = SummPairs(SecondCenter, MultiplyPair(FirstCenter, -1));
    float norm = std::sqrt(std::get<0>(X)*std::get<0>(X) + std::get<1>(X)*std::get<1>(X));
    X = MultiplyPair(X, 1/norm);
    float x0 = std::get<0>(X);
    float x1 = std::get<1>(X);
    float y1, y0;
    if (std::get<0>(X) >= 0){
        y1 = std::sqrt(1/(x0*x0 + x1*x1))*x0;
        y0 = -1*x1*y1/x0;
    }
    else{
        y1 = -1*std::sqrt(1/(x0*x0 + x1*x1))*x0;
        y0 = -1*x1*y1/x0;
    }
    std::pair<float, float> Y = std::make_pair(y0, y1);
    MoveSpeedToNewCoords(Object1, X, Y);
    MoveSpeedToNewCoords(Object2, X, Y);
};
//This one too

void ElasticCollision(GameObject Object1, GameObject Object2){
    GoToNewCoords(Object1, Object2);
    float P0 = std::get<0>(Object1.speed)*Object1.mass + std::get<0>(Object2.speed)*Object2.mass;
    float E0 = (std::pow(std::get<0>(Object1.speed), 2) + std::pow(std::get<1>(Object1.speed), 2))*Object1.mass +
            (std::pow(std::get<0>(Object2.speed), 2) + std::pow(std::get<1>(Object2.speed), 2))*Object2.mass;
    //FIXME - here must be solution of equation system, but I dunno one of needed conditions
    };
//Model of elastic collision

void SolveCollision(GameObject Object1, GameObject Object2){
    float AdditionalTime = 0;
    float step = 0.005*(resources.CurrentFrameTime - resources.LastFrameTime);
    while (TheyCollided(Object1, Object2)){
        MoveObject(Object1, -1*step);
        MoveObject(Object2, -1*step);
        AdditionalTime += step;
    }
    ElasticCollision(Object1, Object2);
    MoveObject(Object1, AdditionalTime);
    MoveObject(Object2, AdditionalTime);
};
//Universal collision solver. Now can solve only elastic collisions

void CheckCollisions(){
    std::vector<GameObject> objects = resources.Objects;
    for (int i = 0; i < objects.size(); i++) {
        for (int j = i + 1; j < objects.size(); j++){
            if (IsIn("Collider", objects[i].ComponentsVector) & IsIn("Collider", objects[j].ComponentsVector)){
                if (TheyCollided(objects[i], objects[j]))
                    SolveCollision(objects[i], objects[j]);
            }
        }
    }
};
//Find and solve collisions

void MoveColliders(){
    std::vector<GameObject> ObjectVector = resources.Objects;
    float TimePassed = resources.CurrentFrameTime - resources.LastFrameTime;
    CheckForces();
    for (int i = 0; i < ObjectVector.size(); i++) {
        MoveObject(ObjectVector[i], TimePassed);
    }
    CheckCollisions();
};
//MoveDots and RotateObjects and checks everything in case of collisions. Also will contain Gravity and some effects.
//Must work in cycle
