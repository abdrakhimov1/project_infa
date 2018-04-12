//
// Created by ruby on 22.03.18.
//

#include "resources.h"

Resources::Resources(){

    sf::ContextSettings settings;
    settings.antialisingLevel = 8;
    window = new sf::RenderWindow(sf::VideoMode(1280, 960), "GAME", sf::Style::Default, settings);
}

sf::RenderWindow& Resources::getWindow(){
    return *window;
}

void Resources::clearWindow() {
    sf::RenderWindow& window = getWindow();
    window.clear();
}

void Resources::displayWindow() {
    sf::RenderWindow& window = getWindow();
    window.display();
}

void Resources::addObject(GameObject object){
    this -> Objects.push_back(object);
}

Resources& Resources::getInstance() {
    static Resources  instance;
    return instance;
}
