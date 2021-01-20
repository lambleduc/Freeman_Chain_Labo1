#pragma once
#include <iostream>

struct Sshape
{
	Sshape();
	~Sshape();
private:
	int coordX;
	int coordY;
	//We will determine the size of array from this number
	int freemanNumber;
	unsigned char* codeFreeman;
} ;

//struct Sshape* shapes;

