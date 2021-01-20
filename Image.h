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
	void setNbShape(int number);
	void setNbRow(int number);

	void readFreemanCodeFile(string pathFreemanCodeFile);
	void stockFreemanCodeInfos(unsigned char* completeStringFile);

private:
	int mNbShape=0;
	int mNbRow=0;
	int mNbColumn=0;
};
