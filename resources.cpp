//
// Created by ruby on 22.03.18.
//

#include "resources.h"
Resources::Resources(){}

    Window::Window() {
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;
        window = new sf::RenderWindow(sf::VideoMode(1280, 960), "GAME", sf::Style::Default, settings);
    }

sf::RenderWindow& Window::getWindow(){
    Resources::getInstance().window;
}

void Window::clearWindow() {
    sf::RenderWindow& window = Window::getWindow();
    window.clear();
}

void Window::displayWindow() {
    sf::RenderWindow& window = Window::getWindow();
    window.display();
}

void Resources::addObject(GameObject object){
    this -> Objects.push_back(object);
}

Resources& Resources::getInstance() {
    static Resources instance;
    return instance;
}
