#pragma once
#ifndef VECT_2D_H
#define VECT_2D_H


#include <string>


class Vect2d
{
public:
   
    Vect2d(float x = 0.0f, float y = 0.0f);
    ~Vect2d();

    // getters
    float x() const;
    float y() const;
    float norm_squared();
    float norm();
    float theta(); // radians

    // setters
    void setX(float x);
    void setY(float y);
    void set(float x = 0, float y = 0);
    void setPolar(float norm, float thetaRadians);

    // Functions
    float distance_squared(Vect2d other);
    float distance(Vect2d other);
    float randomNumber(float Min, float Max);

    std::string toString();

private:
    float mX;
    float mY;
};


#endif // VECT_2D_H

