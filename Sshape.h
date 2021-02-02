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
	

	void setCoordX(int coordX);
	void setCoordY(int coordY);
	void setFreemanNumber(int freemanNumber);
	void setCodeFreeman(int** codeFreeman);

	void createPixels();
	void findPixelCoordinate(int direction, Pixel& pixel, int* currentXCoord, int* currentYCoord);

private:
	int mCoordX;
	int mCoordY;
	//We will determine the size of array from this number
	int mFreemanNumber;
	int* mCodeFreeman;
	Pixel** mPixels;
} ;

//struct Sshape* shapes;

