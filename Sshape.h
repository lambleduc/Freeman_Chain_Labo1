#pragma once
#include <iostream>
#include "Pixel.h"

using namespace std;

struct Sshape
{
	Sshape();
	~Sshape();
	void destroy(Pixel** ptr, int row);
	int coordX();
	int coordY();
	int freemanNumber();
	Pixel** pixels();

	void displayCodeFreeman();
	int* leftBorder;
	int* rightBorder;
	int Aire();
	int Perimetre();

	void setAire(int aire);
	void calculatePerimeter();
	void setCoordX(int coordX);
	void setCoordY(int coordY);
	void setFreemanNumber(int freemanNumber);
	void setCodeFreeman(int* codeFreeman);
	int nbPixels();
	void createPixels();
	void findPixelCoordinate(int direction, Pixel& pixel, int* currentXCoord, int* currentYCoord);

private:
	int mCoordX;
	int mCoordY;
	int mPerimetre=0;
	int mAire=0;
	int mNbPixels = 0;
	//We will determine the size of array from this number
	int mFreemanNumber;
	int* mCodeFreeman;
	Pixel** mPixels;
};

