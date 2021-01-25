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
	return mNbShape;
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
		//char n = ' ';
		int rowDigits = 0;
		int columnDigits = 0;
		int shapeDigits = 0;
		switch (lineIterator)
		{
		case 0:
			//not really sexy ...
			while (line[rowDigits] != ' ') {
				rowDigits++;
			}
			mNbRow = convertCharToIntArray(line, rowDigits, 0);

		/*	Here, we simply state that the number of digits in our column coordinate will be equal to the length of the line minus the number
			of digits in our row coordinate, minus the "space" digit*/
			columnDigits = line.size() - rowDigits- 1;

			//From here on, work in progress still
			mNbColumn = convertCharToIntArray(line, columnDigits, rowDigits + 1);

			break;
		case 1:
			while (line[shapeDigits] != '\0') {
				shapeDigits++;
			}
			
			mNbShape = convertCharToIntArray(line, shapeDigits, 0);

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

int Image::convertCharToIntArray(string line, int length, int startDigit)
{
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += (((int)line[i + startDigit]) - (int)'0') * pow(10, length - 1 - i);
	}
	return sum;
}

void Image::stockFreemanCodeInfos(char & completeStringFile)
{
	// start with a conversion of chars to int


	//create an array of Sshape
	Sshape** sshapeArray = new Sshape*[mNbShape];
	// ****will probably have to stock the size of each row beforehand
	
	//loop on shape objects
	//for (int i = 0; i < mNbShape; i++)
	//{
	//	Sshape shapesFreemanCode;
	//	sshapeArray[i] = &shapesFreemanCode;
	//	shapesFreemanCode.setCoordX();
	//	shapesFreemanCode.setCoordY();
	//	shapesFreemanCode.setFreemanNumber();
	//	shapesFreemanCode
	//	
	//}

}

void Image::createShape()
{
	Sshape shape;
	//shape.coordX =  
}

