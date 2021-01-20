#include "Image.h"


Image::Image()
	:
	mNbColumn{0},
	mNbRow{0},
	mNbShape{0}
{
	readFreemanCodeFile("FreemanCode.txt");
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

void Image::setNbShape(int shapeCount)
{
	mNbShape = shapeCount;
}

void Image::setNbRow(int rowCount)
{
	mNbRow = rowCount;
}

void Image::readFreemanCodeFile(string pathFreemanCodeFile)
{
	
	std::string line;
	std::ifstream fileFreeman(pathFreemanCodeFile);
	int lineIterator = 0;
	while (getline(fileFreeman, line)) 
	{
		switch (lineIterator)
		{
		case 0:
			mNbRow = line[0];
			//not really sexy ...
			mNbRow = (int) mNbRow - 48;
			mNbColumn = line[1];
			mNbColumn = (int) mNbColumn - 48;
			break;
		case 1:
			mNbShape = line[0];
			break;
		}
		lineIterator++;
		std::cout << line << '\n';
	}
	
	//create an instance of ifstream
	ifstream freemanCodeTextFile;
	freemanCodeTextFile.open(pathFreemanCodeFile);

	if (freemanCodeTextFile.is_open()) {
		// save the file as one string to start
		char * completeFile = new char[freemanCodeTextFile.gcount()];

		for (int i = 0; i < freemanCodeTextFile.gcount(); i++)
		{
			freemanCodeTextFile >> completeFile[i];
			if (freemanCodeTextFile.eof())
				break;
			cout << completeFile[i];
		}	
		
		delete[] completeFile;
	}
}

int Image::convertCharToInt(char charact) 
{
	int convertedInt = charact - '0';
	return convertedInt;
}

void Image::convertCharToIntArray(char* lineOfCharac, int * lineOfInt)
{
	 
}

void Image::stockFreemanCodeInfos(unsigned char * completeStringFile)
{
	
}

void Image::createShape()
{
	Sshape shape;
	//shape.coordX =  
}

