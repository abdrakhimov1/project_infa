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
    //std::cout << "Type in the name of object";
    //std::cin >> obj_name;
    texture.loadFromFile(obj_name);
    return texture;
}

Sprite::Sprite(GameObject& object) {
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
    mean_x = getX(centre.crs);
    mean_y = getY(centre.crs);
    sprite.setPosition(mean_x, mean_y);
}

void Sprite::draw() {
    sf::RenderWindow& window = Window::getWindow();
    while (window.isOpen()) {
        window.draw(this -> sprite);
    }
}