//
// Created by fantom on 06.04.18.
//

#include "AnaliticGeometry.h"


std::pair<float, float> FindVectorCoordinatesInNewBasis(std::pair<float, float> Vector,
                                                        std::pair<std::pair<float, float>, std::pair<float, float>> NewBasis){
    std::pair<float, float> X = std::get<0>(NewBasis);
    std::pair<float, float> Y = std::get<1>(NewBasis);
    float Vx0, Vy0, Vx1, Vy1, x1, y1, x2, y2;
    Vx0 = std::get<0>(Vector);
    Vy0 = std::get<1>(Vector);
    x1 = std::get<0>(X);
    x2 = std::get<1>(X);
    y1 = std::get<0>(Y);
    y2 = std::get<1>(Y);
    Vy1 = (Vy0*x1 - Vx0*x2)/(x1*y2 - x2*y1);
    Vx1 = Vx0/x1 - Vy1*y1/x1;
    Vector = std::make_pair(Vx1, Vy1);
    return Vector;
};
//Some technical shit, don't touch it

std::pair<std::pair<float, float>, std::pair<float, float>> FindNewBasisForCollision(GameObject* Object1, GameObject* Object2){
    std::pair<float, float> FirstCenter = Object1 -> getComponent<Collider>().calculateMassCentre().crs;
    std::pair<float, float> SecondCenter = Object2 -> getComponent<Collider>().calculateMassCentre().crs;
    std::pair<float, float> X = SecondCenter + FirstCenter*(-1);
    float norm = std::sqrt(std::get<0>(X)*std::get<0>(X) + std::get<1>(X)*std::get<1>(X));
    X = X*(1/norm);
    float x0 = std::get<0>(X);
    float x1 = std::get<1>(X);
    float y1, y0;
    if (std::get<0>(X) >= 0){
        y1 = std::sqrt(1/(x0*x0 + x1*x1))*x0;
        y0 = -1*x1*y1/x0;
    }
    else{
        y1 = -1*std::sqrt(1/(x0*x0 + x1*x1))*x0;
        y0 = -1*x1*y1/x0;
    }
    std::pair<float, float> Y = std::make_pair(y0, y1);
    return std::make_pair(X, Y);
};
//This one too

float operator-(Dot dot1, Dot dot2){
    float x1, y1, x2, y2, distance;
    x1 = std::get<0>(dot1.crs);
    y1 = std::get<1>(dot1.crs);
    x2 = std::get<0>(dot2.crs);
    y2 = std::get<1>(dot2.crs);
    distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    return distance;
}

std::pair<std::pair<float, float>, std::pair<float, float>> findMainBasisCoords(std::pair<std::pair<float, float>, std::pair<float, float>> Basis){
    std::pair<float, float> X = std::get<0>(Basis);
    std::pair<float, float> Y = std::get<1>(Basis);
    float x1, y1, x2, y2;
    x1 = std::get<0>(X);
    y1 = std::get<1>(X);
    x2 = std::get<0>(Y);
    y2 = std::get<1>(Y);
    Y = std::make_pair(-1*x2/(y2*x1 - y1*x2), x1/(y2*x1 - y1*x2));
    X = std::make_pair(y2/(y2*x1 - y1*x2), -1*y1/(y2*x1 - y1*x2));
    return std::make_pair(X, Y);
};

std::pair<float, float> solveEqulationSystem(float P0, double E0, float m1, float m2, float Vx2, float Vx1){
    Vx1 = -1*Vx1;
    Vx2 = -1*Vx2;
    /*
    double D = std::pow(m2*P0, 2) - m1*m2*(m1 + m2)*(std::pow(P0, 2)*m2 - E0*m1*m1);
    assert (D > 0);
    double Vx2 = (m2*P0 + std::sqrt(D))/m1*m2*(m1 + m2);
    if (std::abs(Vx2_0) - std::abs(Vx2) < 0) Vx2 = (m2*P0 - std::sqrt(D))/m1*m2*(m1 + m2);
    float Vx1 = (P0 - m2*Vx2)/m1;
     */
    return std::make_pair(Vx1, Vx2);
};
//FIXME