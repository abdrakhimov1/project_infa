//
// Created by fantom on 04.04.18.
//

class StupidObject
{
public:
    std::pair<float, float> speed;
    std::vector<Dot> dots_list;
    std::vector<std::string> ComponentsVector;
    float mass;                             //Put it in Collider
    std::pair<float, float> MassCenter;     //This too
    StupidObject()
    {
        ComponentsVector.push_back("RigidBody");
        ComponentsVector.push_back("Collider");
        ComponentsVector.push_back("DrawMe");
    }

    void DrawMe();

    void Add_dot(Dot dot, std::vector<Dot> dots_list){
        dots_list.push_back(dot);
    }

    bool Detect(float dotX, float dotY, float X0, float Y0, float X1, float Y1){
        float d = (dotX - X0) * (Y1 - Y0) - (dotY - Y0) * (X1 - X0);
        return d > 0;
    }

};