#include "Vect2d.h"


//Fichier: Vect2d.cpp
//GPA665 - Projet 1
//Création:
//    -L.Leduc
//    -F.B
//---------------------------
//2d vector class
//---------------------------


Vect2d::Vect2d(float x, float y)
    : mX{ x }, mY{ y }
{
}

Vect2d::~Vect2d()
{
    
}

float Vect2d::x() const
{
    return mX;
}

float Vect2d::y() const
{
    return mY;
}

float Vect2d::norm_squared()
{
    return mX * mX + mY * mY;
}

float Vect2d::norm()
{
    return std::sqrt(norm_squared());
}

float Vect2d::randomNumber(float Min, float Max)
{
    return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

float Vect2d::theta()
{
    return std::atan2(mY, mX);
}

void Vect2d::setX(float x)
{
    mX = x;
}

void Vect2d::setY(float y)
{
    mY = y;
}

void Vect2d::set(float x, float y)
{
    setX(x);
    setY(y);
}

void Vect2d::setPolar(float norm, float thetaRadians)
{
    setX(norm * std::cos(thetaRadians));
    setY(norm * std::sin(thetaRadians));
}

float Vect2d::distance_squared(Vect2d other)
{
    return std::pow(mX - other.mX, 2.0f) + std::pow(mY - other.mY, 2.0f);
}

float Vect2d::distance(Vect2d other)
{
    return std::sqrt(distance_squared(other));
}

std::string Vect2d::toString()
{
    std::stringstream stream;
    stream << "(" << mX << ", " << mY << ")";
    return stream.str();
}
