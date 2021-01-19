#pragma once
#include <iostream>

struct Sshape
{
	Sshape();
	~Sshape();
	
	int CoordX;
	int CoordY;
	//We will determine the size of array from this number
	int FreemanNumber;
	unsigned char* CodeFreeman;
} Sshape;

struct Sshape* shapes;

