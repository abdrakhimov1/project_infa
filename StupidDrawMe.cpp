#include "StupidDrawMe.h"

StDrawMe::StDrawMe(Triangle triangle) {
        Window::clearWindow();
        triangle.draw();
        Window::displayWindow();
}


StDrawMe::~StDrawMe() {
    Window::clearWindow();
    Window::displayWindow();
}
