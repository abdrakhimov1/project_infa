//
// Created by fantom on 04.04.18.
//

class StupidObject
{
public:
    std::pair<float, float> speed;
    std::vector<Dot> dots_list;
    std::vector<std::string> ComponentsVector;
    float mass;                             //Put it in RigidBody
    std::pair<float, float> MassCenter;     //This too
    StupidObject() {
        ComponentsVector.push_back("RigidBody");
        ComponentsVector.push_back("Collider");
        ComponentsVector.push_back("DrawMe");
    };

    void DrawMe();

    void Add_dot(Dot dot, std::vector<Dot> dots_list){
        dots_list.push_back(dot);
    }
};