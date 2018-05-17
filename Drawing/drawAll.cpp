//
// Created by fantom on 04.05.18.
//

#include "drawAll.h"

void drawAll(){
    while (Window::getWindow().isOpen()){
        Resources::getInstance().accessToResourses.lock();
        Window::clearWindow();
        for (int i = 0; i < Resources::getInstance().Objects.size(); i++){
            Resources::getInstance().Objects[i].getComponent<DrawMe>().Draw();
        }
        Window::displayWindow();
        while (Window::getWindow().pollEvent(Resources::getInstance().event)) {
            switch (Resources::getInstance().event.type) {
                case sf::Event::Closed:
                    Window::getWindow().close();
                    break;
            }
        }
        Resources::getInstance().accessToResourses.unlock();
    }
}