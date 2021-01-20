#pragma once
#define Image_H
#include <iostream>
#include <string>
#include <fstream>

#include "Sshape.h"

using namespace std;

class Image
{
public:
	Image();
	~Image();
	int nbShape();
	int nbRow();
	int nbColumn();
	//Check the setters' relevancy considering the initializer
	void setNbShape(int shapeCount);
	void setNbRow(int rowCount);

	void readFreemanCodeFile(string pathFreemanCodeFile);
	int convertCharToInt(char charact);
	void convertCharToIntArray(char* lineOfCharac, int* lineOfInt);
	void stockFreemanCodeInfos(unsigned char* completeStringFile);
	// Creates an instance of Sshape
	void createShape();

private:
	int mNbShape;
	int mNbRow;
	int mNbColumn;
};
