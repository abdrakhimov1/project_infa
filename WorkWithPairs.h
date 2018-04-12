//
// Created by fantom on 05.04.18.
// Modified by verwindle on 10.04.18.
//
#include <utility>

#ifndef PROJECT_WORKWITHPAIRS_H
#define PROJECT_WORKWITHPAIRS_H

float getX(std::pair<float, float> pair);

float getY(std::pair<float, float> pair);

std::pair<float, float> operator+(std::pair<float, float> FirstPair, std::pair<float, float> SecondPair);

std::pair<float, float> operator*(std::pair<float, float> Pair, float Number);

#endif //PROJECT_WORKWITHPAIRS_H
