#pragma once
#include <iostream>

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
	int mCoordinates[2];
	bool mBinaryColor;
	bool mIsStartingPoint;
};

