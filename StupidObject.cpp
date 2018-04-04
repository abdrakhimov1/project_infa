//
// Created by fantom on 04.04.18.
//

class StupidObject
{
public:
    std::pair<float, float> speed;
    std::vector<Dot> dots_list;
    std::vector<std::string> ComponentsVector;
    StupidObject()
    {
        ComponentsVector.push_back("RigidBody");
        ComponentsVector.push_back("Collider");
        ComponentsVector.push_back("DrawMe");
    }
    void DrawMe();
};