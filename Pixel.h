#pragma once
#define PIXEL_H
#include <iostream>
#include <vector>
#include "Vect2d.h"

class Pixel
{
public:
	Pixel();
	~Pixel();

	//Getters
	bool binaryColor();
	bool isStartingPoint();

	//Setters
	void setBinaryColor(bool binaryColor);
	void setIsStartingPoint(bool isStartingPoint);

private:
	std::vector<Vect2d> mCoordinates;
	bool mBinaryColor;
	bool mIsStartingPoint;
};

