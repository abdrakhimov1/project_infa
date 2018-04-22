//
// Created by ruby on 05.04.18.
//
#include "Components.h"
#include "resources.h"
AbstractComponent::~AbstractComponent() {}

RigidBody::RigidBody(GameObject& object)
{
    typeID = (char*) typeid(*this).name();
    AbstractComponent::object = &object;
}

RigidBody::~RigidBody() {}

void RigidBody::make() {}

DrawMe::DrawMe(GameObject& object, Sprite sprite) {
    typeID = (char*) typeid(*this).name();
    AbstractComponent::object = &object;

    Window::clearWindow();
    sprite.draw();
    Window::displayWindow();
    }

Dot DrawMe::setSpriteCentre() {
    float mean_x = getX(object->getComponent<Collider>().calculateMassCentre().crs);
    float mean_y = getY(object->getComponent<Collider>().calculateMassCentre().crs); // it's strange to get co-te from pair and then create pair again, I know
    Dot centre = Dot(mean_x, mean_y);

    return centre;
}

std::vector<Dot> DrawMe::setSpriteCoordinates() {
    std::vector<Dot> crs = {};
    std::vector<Dot> dots = object->getComponent<Collider>().dotsList;
    for (int i = 0;i < dots.size();i++) {
        float crx = getX(dots[i].crs); // crs stands for coordinates
        float cry = getY(dots[i].crs);
        Dot x_and_y = Dot(crx, cry);
        crs.push_back(x_and_y);
    }

    return crs;
}

DrawMe::~DrawMe() {
    Window::clearWindow();
    Window::displayWindow();
}

Collider::Collider(GameObject& object) {
    typeID = (char*) typeid(*this).name();
    AbstractComponent::object = &object;
}

Collider::~Collider() {}

void Collider::make() {}

Dot Collider::calculateMassCentre() {
    Dot centre = Dot(0, 0);
    std::vector<Dot> dots = dotsList;

    float number_of_dots = sizeof(dots);
    for (auto dot : dots) {
        centre.crs = centre.crs + dot.crs;
    }
    centre.crs = centre.crs/number_of_dots;
    return centre;
}

void Collider::Add_dot(Dot dot){
    this -> dotsList.push_back(dot);
}
/*
class AbstractComponent{
public:
    virtual ~AbstractComponent(){}
    virtual void make() = 0;
    const char* typeID;
};


class RigidBody : public AbstractComponent{
public:
    RigidBody(){typeID = (char*) typeid(*this).name();}
    ~RigidBody(){}
    void make(){}
    std::pair<float, float> speed;
    float mass;
    int a = 12;
};

class Collider : public AbstractComponent{
public:
    Collider(){typeID = (char*) typeid(*this).name();}
    ~Collider(){}
    void make(){}
    std::vector<Dot> dotsList;
    Dot massCentre;
    void Add_dot(Dot dot, std::vector<Dot> dots_list){
        dots_list.push_back(dot);
    }
    int k = 11;
};
*/