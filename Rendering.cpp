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
    std::cout << "Sprite" << ' ' << '0' << std::endl;
    quantity_of_dots = object.getComponent<Collider>().dotsList.size();
    std::cout << "Sprite" << ' ' << '1' << std::endl;
    obj_name = texture_name;
    std::cout << "Sprite" << ' ' << '2' << std::endl;
    convex.setPointCount(quantity_of_dots);
    std::cout << "Sprite" << ' ' << '3' << std::endl;
    std::vector<Dot> crs = object.getComponent<DrawMe>().setSpriteCoordinates();
    std::cout << "Sprite" << ' ' << '4' << std::endl;
    for (int i = 0; i < quantity_of_dots; i++) {
        std::cout << "Sprite" << ' ' << '0' << i << std::endl;
        sf::Vector2f coords = getVectorFromPair(crs[i].crs);
        std::cout << "Sprite" << ' ' << '1' << i << std::endl;
        convex.setPoint(i, coords);
        std::cout << "Sprite" << ' ' << '2' << i << std::endl;
        //i++;
    }
    std::cout << "Sprite" << ' ' << '5' << std::endl;
    convex.setOutlineThickness(1); // collision mask
    std::cout << "Sprite" << ' ' << '6' << std::endl;
    convex.setOutlineColor(mask_color);
    std::cout << "Sprite" << ' ' << '7' << std::endl;
    Sprite::setTexture();
    std::cout << "Sprite" << ' ' << '8' << std::endl;
    sprite.setTexture(texture);
    std::cout << "Sprite" << ' ' << '9' << std::endl;
    Dot centre = object.getComponent<DrawMe>().setSpriteCentre();
    std::cout << "Sprite" << ' ' << "10" << std::endl;
    std::get<0>(centre.crs) = getX(centre.crs);
    std::cout << "Sprite" << ' ' << "11" << std::endl;
    std::get<1>(centre.crs) = getY(centre.crs);
    std::cout << "Sprite" << ' ' << "12" << std::endl;
    sprite.setPosition(std::get<0>(centre.crs), std::get<1>(centre.crs));
    std::cout << "Sprite" << ' ' << "13" << std::endl;
}

void Sprite::draw() {
    sf::RenderWindow& window = Window::getWindow();
    while (window.isOpen()) {
        window.draw(this -> sprite);
    }
}