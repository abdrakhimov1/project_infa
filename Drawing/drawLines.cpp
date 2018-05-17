//
// Created by fantom on 10.05.18.
//

#include "drawLines.h"
#include "../Staff/allLibraries.h"
#include "../Resources/GameObject.h"
#include "../Resources/resources.h"
#include "../Logic/ConverterPairToVector2.h"

void drawLines(){
    while (Window::getWindow().isOpen()){
        //Resources::getInstance().accessToResourses.lock();
        Window::clearWindow();
        for (int i = 0; i < Resources::getInstance().Objects.size(); i++){
            sf::VertexArray tmpArray(sf::LinesStrip, 4);
            tmpArray[0].position = getVectorFromPair(Resources::getInstance().Objects[i].getComponent<Collider>().dotsList[0].crs);
            tmpArray[1].position = getVectorFromPair(Resources::getInstance().Objects[i].getComponent<Collider>().dotsList[1].crs);
            tmpArray[2].position = getVectorFromPair(Resources::getInstance().Objects[i].getComponent<Collider>().dotsList[2].crs);
            tmpArray[3].position = getVectorFromPair(Resources::getInstance().Objects[i].getComponent<Collider>().dotsList[0].crs);
            tmpArray[0].color = sf::Color::Green;
            tmpArray[1].color = sf::Color::Green;
            tmpArray[2].color = sf::Color::Green;
            tmpArray[3].color = sf::Color::Green;
            Window::getWindow().draw(tmpArray);
        }
        Window::displayWindow();
        while (Window::getWindow().pollEvent(Resources::getInstance().event)) {
            switch (Resources::getInstance().event.type) {
                case sf::Event::Closed:
                    Window::getWindow().close();
                    break;
            }
        }
        //Resources::getInstance().accessToResourses.unlock();
    }
}