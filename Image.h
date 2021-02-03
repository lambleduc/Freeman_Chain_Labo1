#pragma once
#define Image_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Sshape.h"

#define INDEX_FREEMAN_START 2
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
	void stockFreemanCodeInfos(Sshape & shapeArray, string line);
	void getSpecificLine(ifstream & textFile, int desiredLineOfFile, string& adresseOfFile);
	void readAssociatedFreemanCodeLine(Sshape & shapesFreemanCode, string Line, int codeSize, int startFreeman);
	void screenDisplay();


private:
	int mNbShape=0;
	int mNbRow=0;
	int mNbColumn=0;
	Sshape** mSshapeArray;
};
