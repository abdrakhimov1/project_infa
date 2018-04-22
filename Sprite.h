//
// Created by verwindle on 12.04.18.
//

#ifndef PROJECT_INFA_SPRITE_H
#define PROJECT_INFA_SPRITE_H

class Sprite {
private:
    sf::Sprite sprite;
    sf::ConvexShape convex;
    sf::Texture texture;
    Dot centre;
    float mean_x;
    float mean_y;
public:
    Sprite();

    const std::string obj_name;
    sf::Texture setTexture( );
  
    std::vector<Dot> dots;
    //sf::Color Dan_favourite_color = sf::Color(7, 55, 221); sorry, Dan
    int quantity_of_dots;

    std::vector<Dot> crs;
    sf::Color mask_color = sf::Color::Black; // collision mask

    void draw();
};

#endif //PROJECT_INFA_SPRITE_H