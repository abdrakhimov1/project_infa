//
// Created by ruby on 22.03.18.
//

#include "resources.h"
Resources::Resources(){
    Timer.restart();
}

Window::Window() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow(sf::VideoMode(1280, 960), "GAME", sf::Style::Default, settings);
}

sf::RenderWindow& Window::getWindow(){
    static Window SevaHuesos;
    return *SevaHuesos.window;
}

void Window::clearWindow() {
    Window::getWindow().clear();
}

void Window::displayWindow() {
    Window::getWindow().display();
}

void Resources::addObject(GameObject object){
    this -> Objects.push_back(object);
}

Resources& Resources::getInstance() {
    static Resources instance;
    return instance;
}
