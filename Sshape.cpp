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

Pixel** Sshape::pixels()
{
	return mPixels;
}

void Sshape::displayCodeFreeman()
{
	for (int i = 0; i < mFreemanNumber; i++)
	{
		std::cout << mCodeFreeman[i] << ' ';
	}
	std::cout << std::endl;

}

int Sshape::Aire()
{
	return mAire;
}

int Sshape::Perimetre()
{
	return mPerimetre;
}

void Sshape::setAire(int aire)
{
	mAire = aire;
}

void Sshape::calculatePerimeter()
{
	for (int i = 0; i < mFreemanNumber; i++)
	{
		switch (mCodeFreeman[i]) {
		case(0):
		case(2):
		case(4):
		case(6):
			mPerimetre += 1;
			break;
		case(1):
		case(3):
		case(5):
		case(7):
			mPerimetre += sqrt(2);
			break;
		}

	}
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

int Sshape::nbPixels()
{
	return mNbPixels;
}

void Sshape::createPixels()
{
	int currentX = mCoordX;
	int currentY = mCoordY;
	int* tempXCoord = &currentX;
	int* tempYCoord = &currentY;

	mPixels = new Pixel * [mFreemanNumber];
	mNbPixels = mFreemanNumber;
	for (int i = 0; i < mFreemanNumber; i++)
	{
		mPixels[i] = new Pixel();
		if (i == 0)
		{
			// create the starting pixel from coordx, coordy

			mPixels[i]->setCoordinates(mCoordX, mCoordY);
			mPixels[i]->setIsStartingPoint(true);
		}
		else
		{

			findPixelCoordinate(mCodeFreeman[i - 1], *mPixels[i], tempXCoord, tempYCoord);

		}


	}
}

void Sshape::findPixelCoordinate(int direction, Pixel& pixel, int* currentXCoord, int* currentYCoord)
{

	switch (direction)
	{
	case 1:
		// x : -1 , y : +1
		*currentXCoord -= 1;
		*currentYCoord += 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 2:
		// x : +0 , y : +1
		*currentYCoord += 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 3:
		// x : +1 , y : +1
		*currentXCoord += 1;
		*currentYCoord += 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 4:
		// x : +1 , y : +0
		*currentXCoord += 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 5:
		// x : + 1 , y : -1
		*currentXCoord += 1;
		*currentYCoord -= 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 6:
		// x : +0 , y : -1
		*currentYCoord -= 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 7:
		// x : -1 , y : -1
		*currentXCoord -= 1;
		*currentYCoord -= 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	case 0:
		// x : -1, y : 0
		*currentXCoord -= 1;
		pixel.setCoordinates(*currentXCoord, *currentYCoord);
		break;
	}

}

