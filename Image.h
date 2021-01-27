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
	int convertCharToIntArray(string line, int length, int startDigit);
	void stockFreemanCodeInfos(ifstream & fileFreeman);
	void getSpecificLine(ifstream & textFile, int desiredLineOfFile, string& adresseOfFile);
	// Creates an instance of Sshape
	void createShape();

private:
	int mNbShape=0;
	int mNbRow=0;
	int mNbColumn=0;
};
