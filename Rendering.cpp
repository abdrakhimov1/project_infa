#include "ConverterPairToVector2.h"
#include "Sprite.h"

sf::Vector2f getVectorFromPair(std::pair<float, float> coords) {
    float crx = std::get<0>(coords);
    float cry = std::get<1>(coords);
    sf::Vector2f vector(crx, cry);

    return vector;
}


Sprite::setTexture() {
    std::cout << "Type in the name of object";
    std::cin >> obj_name;
    texture = texture.loadFromFile(obj_name);
    return texture;
}

Sprite::Sprite() {
    convex.setPointCount(quantity_of_dots);
   std::vector<Dot> crs = DrawMe::setSpriteCoordinates();
    for (int i = 0; i < quantity_of_dots; i++) {
        sf::Vector2f coords = getVectorFromPair(crs[i].crs);
        convex.setPoint(i, coords);
        i++; }

    convex.setOutlineThickness(1); // collision mask
    convex.setOutlineColor(mask_color);

    setTexture();
    sprite.setTexture(texture);
    //sprite.setColor(Dan_favourite_color); // sorry, Dan
    Dot centre = DrawMe::setSpriteCentre();
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