//
// Created by ruby on 22.03.18.
//

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "resources.h"

Resources::Resources(){
    window = new sf::RenderWindow(sf::VideoMode(1280, 960), "GAME");
}

sf::RenderWindow& Resources::getWindow(){
    return *window;
}

void Resources::addObject(GameObject object){
    this -> Objects.push_back(object);
}

Resources& Resources::getInstance() {
    static Resources  instance;
    return instance;
}
