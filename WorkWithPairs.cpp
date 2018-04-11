//
// Created by fantom on 05.04.18.
//

#include "WorkWithPairs.h"

std::pair<float, float> operator+(std::pair<float, float> FirstPair, std::pair<float, float> SecondPair){
    float TMP1 = std::get<0>(FirstPair) + std::get<0>(SecondPair);
    float TMP2 = std::get<1>(FirstPair) + std::get<1>(SecondPair);
    return std::make_pair(TMP1, TMP2);
};

std::pair<float, float> operator*(std::pair<float, float> Pair, float Number){
    float TMP1 = std::get<0>(Pair)*Number;
    float TMP2 = std::get<1>(Pair)*Number;
    return std::make_pair(TMP1, TMP2);
};
