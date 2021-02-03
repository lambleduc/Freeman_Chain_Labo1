#include "Sshape.h"


Sshape::Sshape()
{
	//initialize to 0
}

Sshape::~Sshape()
{
}

int Sshape::coordX()
{
	return mCoordX;
}

int Sshape::coordY()
{
	return mCoordY;
}

int Sshape::freemanNumber()
{
	return mFreemanNumber;
}

void Sshape::displayCodeFreeman()
{
	for (int i = 0; i < mFreemanNumber; i++)
	{
		std::cout << mCodeFreeman[i] << ' ';
	}
	std::cout << std::endl;
		
}

void Sshape::setCoordX(int coordX)
{
	mCoordX = coordX;
}

void Sshape::setCoordY(int coordY)
{
	mCoordY = coordY;
}

void Sshape::setFreemanNumber(int freemanNumber)
{
	mFreemanNumber = freemanNumber;
}

void Sshape::setCodeFreeman(int* codeFreeman)
{
	mCodeFreeman = codeFreeman;
}

void Sshape::createPixels()
{
	int currentX = mCoordX;
	int currentY = mCoordY;
	int* tempXCoord = &currentX;
	int* tempYCoord = &currentY;

	for (int i = 0; i < mFreemanNumber; i++)
	{
		if(i == 0)
		{
			// create the starting pixel from coordx, coordy
			Pixel pixel{};
			pixel.setCoordinates(mCoordX, mCoordY);
		}
		else 
		{
			Pixel pixel{};
			findPixelCoordinate(mCodeFreeman[i+3], pixel, tempXCoord, tempYCoord);
		}
	}
}

void Sshape::findPixelCoordinate(int direction, Pixel & pixel, int* currentXCoord, int* currentYCoord)
{
	int** xValue = &currentXCoord;
	int** yValue = &currentYCoord;
	switch (direction)
	{
	case 1:
		// x : -1 , y : +1

		pixel.setCoordinates(**xValue - 1, **yValue + 1);
		break;
	case 2:
		// x : +0 , y : +1
		pixel.setCoordinates(**xValue + 0, **yValue + 1);
		break;
	case 3:
		// x : +1 , y : +1
		pixel.setCoordinates(**xValue + 1, **yValue + 1);
		break;
	case 4:
		// x : +1 , y : +0
		pixel.setCoordinates(**xValue + 1, **yValue + 0);
		break;
	case 5:
		// x : + 1 , y : -1
		pixel.setCoordinates(**xValue + 1, **yValue - 1);
		break;
	case 6:
		// x : +0 , y : -1
		pixel.setCoordinates(**xValue + 0, **yValue - 1);
		break;
	case 7:
		// x : -1 , y : -1
		pixel.setCoordinates(**xValue - 1, **yValue - 1);
		break;
	}
}

