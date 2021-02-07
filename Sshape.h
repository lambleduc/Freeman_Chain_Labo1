#pragma once
#include <iostream>
#include "Pixel.h"

struct Sshape
{
	Sshape();
	~Sshape();
	int coordX();
	int coordY();
	int freemanNumber();
	Pixel** pixels();

	void displayCodeFreeman();
	int* leftBorder;
	int* rightBorder;

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

	int mNbPixels = 0;
	//We will determine the size of array from this number
	int mFreemanNumber;
	int* mCodeFreeman;
	Pixel** mPixels;
};

//struct Sshape* shapes;

