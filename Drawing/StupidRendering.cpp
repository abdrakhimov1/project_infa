#include "../Logic/ConverterPairToVector2.h"
#include "../Resources/Triangle.h"
#include "StupidDrawMe.h"

Dot Triangle::triangleMassCentre() {
    Dot centre = Dot(0, 0);
    std::vector<Dot> dots = {Dot(0,87), Dot(50,0), Dot(100,87)};
    float number_of_dots = 3;

    for (int i = 0; i < number_of_dots; ++i) {
        centre.crs = centre.crs + dots[i].crs;
    }
    centre.crs = centre.crs/number_of_dots;
    return centre;
}

Dot Triangle::setSpriteCentre() {
    float mean_x = getX(triangleMassCentre().crs);
    float mean_y = getY(triangleMassCentre().crs);
    Dot centre = Dot(mean_x, mean_y);

    return centre;
}


Triangle::Triangle() {
    sf::CircleShape triangle(100, 3);
    triangle.setFillColor(Dan_favourite_color);
    Dot centre = Triangle::setSpriteCentre();
    float mean_x = getX(centre.crs);
    float mean_y = getY(centre.crs);
    triangle.setPosition(mean_x, mean_y);
}

void Triangle::draw() {
    sf::RenderWindow& window = Window::getWindow();
    while (window.isOpen()) {
        window.draw(this -> triangle);
    }
}