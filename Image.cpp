#include "Image.h"


Image::Image()
	:
	mNbColumn{0},
	mNbRow{0},
	mNbShape{0}
{
	//readFreemanCodeFile("FreemanCode.txt");
}

Image::~Image()
{
}

int Image::nbShape()
{
	return 0;
}

int Image::nbRow()
{
	return 0;
}

int Image::nbColumn()
{
	return 0;
}

void Image::setNbShape(int number)
{
}

void Image::setNbRow(int number)
{
}

void Image::readFreemanCodeFile(string pathFreemanCodeFile)
{
	//create an instance of ifstream
	ifstream freemanCodeTextFile;
	freemanCodeTextFile.open(pathFreemanCodeFile);

	if (freemanCodeTextFile.is_open()) {
		// save the file as one string to start
		string completeFile;
		while (1) {
			freemanCodeTextFile >> completeFile;
			if (freemanCodeTextFile.eof())
				break;
		}
		cout << completeFile;
	}
}

void Image::stockFreemanCodeInfos()
{
}

