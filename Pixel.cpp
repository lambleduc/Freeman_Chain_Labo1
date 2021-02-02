#include "Pixel.h"

Pixel::Pixel()
{
}

Pixel::~Pixel()
{
}

bool Pixel::binaryColor()
{
	return mBinaryColor;
}

bool Pixel::isStartingPoint()
{
	return mIsStartingPoint;
}

Vect2d Pixel::coordinates()
{
	return mCoordinates;
}

void Pixel::setBinaryColor(bool binaryColor)
{
	mBinaryColor = binaryColor;
}

void Pixel::setIsStartingPoint(bool isStartingPoint)
{
	mIsStartingPoint = isStartingPoint;
}

void Pixel::setCoordinates(int x, int y)
{
	mCoordinates.setX(x);
	mCoordinates.setY(y);
}

