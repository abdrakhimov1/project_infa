#include "ConverterPairToVector2.h"
#include "Sprite.h"
#include "resources.h"
#include "Components.h"

sf::Vector2f getVectorFromPair(std::pair<float, float> coords) {
    float crx = std::get<0>(coords);
    float cry = std::get<1>(coords);
    sf::Vector2f vector(crx, cry);

    return vector;
}

sf::Texture Sprite::setTexture() {
    texture.loadFromFile(obj_name);
    return texture;
}

Sprite::Sprite(GameObject& object, std::string texture_name) {
    quantity_of_dots = object.getComponent<Collider>().dotsList.size();
    obj_name = texture_name;
    convex.setPointCount(quantity_of_dots);
    std::vector<Dot> crs = object.getComponent<DrawMe>().setSpriteCoordinates();
    for (int i = 0; i < quantity_of_dots; i++) {
        sf::Vector2f coords = getVectorFromPair(crs[i].crs);
        convex.setPoint(i, coords);
        i++; }

    convex.setOutlineThickness(1); // collision mask
    convex.setOutlineColor(mask_color);

    Sprite::setTexture();
    sprite.setTexture(texture);
    Dot centre = object.getComponent<DrawMe>().setSpriteCentre();
    std::get<0>(centre.crs) = getX(centre.crs);
    std::get<1>(centre.crs) = getY(centre.crs);
    sprite.setPosition(std::get<0>(centre.crs), std::get<1>(centre.crs));
}

void Sprite::draw() {
    sf::RenderWindow& window = Window::getWindow();
    while (window.isOpen()) {
        window.draw(this -> sprite);
    }
}