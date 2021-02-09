#pragma once
#define PIXEL_H
#include <iostream>
#include "Vect2d.h"

using namespace std;

class Pixel
{
public:
	Pixel();
	~Pixel();

	//Getters
	bool binaryColor();
	bool isStartingPoint();
	Vect2d coordinates();

	//Setters
	void setBinaryColor(bool binaryColor);
	void setIsStartingPoint(bool isStartingPoint);
	void setCoordinates(int x, int y);

private:
	Vect2d mCoordinates;
	bool mBinaryColor;
	bool mIsStartingPoint = 0;
};

