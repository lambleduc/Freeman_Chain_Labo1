#include "Sshape.h"

Sshape::Sshape()
{
}

Sshape::~Sshape()
{
}

int Sshape::coordX()
{
	return 0;
}

int Sshape::coordY()
{
	return 0;
}

int Sshape::freemanNumber()
{
	return 0;
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

void Sshape::setCodeFreeman(int* codeFreeman, int freemanNumber)
{
	int* mCodeFreeman = new int[freemanNumber];
	for (int i = 0; i < freemanNumber; i++)
	{
		mCodeFreeman[i] = codeFreeman[i];
	}
}

