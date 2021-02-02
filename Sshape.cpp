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
		std::cout << mCodeFreeman[i];
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

void Sshape::setCodeFreeman(int** codeFreeman)
{
	mCodeFreeman = *codeFreeman;
}

