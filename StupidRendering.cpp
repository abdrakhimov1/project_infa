#include "ConverterPairToVector2.h"
#include "StupidRendering.h"

sf::Vector2f getVectorFromPair(std::pair<float, float> coords) {
    float crx = std::get<0>(coords);
    float cry = std::get<1>(coords);
    sf::Vector2f vector(crx, cry);

    return vector;
}

Dot setSpriteCentre(GameObject object, std::vector<Dot> dots) {
    dots = object.getComponent<Collider>().dotsList;
    float mean_x = getX(object.getComponent<Collider>().calculateMassCentre().crs);
    float mean_y = getY(object.getComponent<Collider>().calculateMassCentre().crs); // it's strange to get co-te from pair and then create pair again, I know
    Dot centre = Dot(mean_x, mean_y);

    return centre;
}


Triangle::Triangle(GameObject object) {
    triangle().setFillColor(Dan_favourite_color);
    centre = setSpriteCentre(object, object.getComponent<Collider>().dotsList);
    mean_x = getX(centre.crs);
    mean_y = getY(centre.crs);
    triangle().setPosition(mean_x, mean_y);
}

void Triangle::draw() {
    sf::RenderWindow& window = Resources::getInstance().getWindow();
    while (window.isOpen()) {
        window.draw(this -> triangle(100, 3));
    }
}