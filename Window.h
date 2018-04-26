//
// Created by verwindle on 19.04.18.
//
#include "allLibraries.h"

#ifndef PROJECT_INFA_WINDOW_H
#define PROJECT_INFA_WINDOW_H

class Window {
protected:
    sf::RenderWindow* window;
    Window();

public:
    static sf::RenderWindow& getWindow();

    static void clearWindow();

    static void displayWindow();
};

#endif //PROJECT_INFA_WINDOW_H