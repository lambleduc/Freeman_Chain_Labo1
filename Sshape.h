#pragma once
#include <iostream>

struct Sshape
{
	Sshape();
	~Sshape();
	int coordX();
	int coordY();
	int freemanNumber();

	void displayCodeFreeman();
	

	void setCoordX(int coordX);
	void setCoordY(int coordY);
	void setFreemanNumber(int freemanNumber);
	void setCodeFreeman(int* codeFreeman);

private:
	int mCoordX;
	int mCoordY;
	//We will determine the size of array from this number
	int mFreemanNumber;
	int* mCodeFreeman;
} ;

//struct Sshape* shapes;

