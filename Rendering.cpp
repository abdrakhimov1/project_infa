#include "ConverterPairToVector2.h"
#include "Rendering.h"
#include "Sprite.h"

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

std::vector<Dot> setSpriteCoordinates(GameObject object) {
    std::vector<Dot> crs = {};
    std::vector<Dot> dots = object.getComponent<Collider>().dotsList;
    for (int i = 0;i < dots.size();i++) {
        float crx = getX(dots[i].crs); // crs stands for coordinates
        float cry = getY(dots[i].crs);
        Dot x_and_y = Dot(crx, cry);
        crs.push_back(x_and_y);
    }

    return crs;
}


Sprite::setTexture() {
    std::cout << "Type in the name of object";
    std::cin >> obj_name;
    texture = texture.loadFromFile(obj_name);
    return texture;
}

Sprite::Sprite(GameObject object) {
    convex.setPointCount(quantity_of_dots);
    for (int i = 0; i < quantity_of_dots; i++) {
        sf::Vector2f coords = getVectorFromPair(crs[i].crs);
        convex.setPoint(i, coords);
        i++; }

    convex.setOutlineThickness(1); // collision mask
    convex.setOutlineColor(mask_color);

    setTexture();
    sprite.setTexture(texture);
    //sprite.setColor(Dan_favourite_color); // sorry, Dan
    centre = setSpriteCentre(object, object.getComponent<Collider>().dotsList);
    mean_x = getX(centre.crs);
    mean_y = getY(centre.crs);
    sprite.setPosition(mean_x, mean_y);
}

void Sprite::draw() {
    sf::RenderWindow& window = Resources::getInstance().getWindow();
    while (window.isOpen()) {
        window.draw(this -> sprite);
    }
}