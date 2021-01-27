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
	std::ifstream fileFreeman;
	fileFreeman.open(pathFreemanCodeFile, std::ifstream::in);
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
	fileFreeman.seekg(0);
	stockFreemanCodeInfos(fileFreeman);
	fileFreeman.close();
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

void Image::stockFreemanCodeInfos(ifstream & fileFreeman)
{
	// On s'intéresse à forme en tant que telles
	// start with a conversion of chars to int

	
	//create an array of Sshape
	Sshape** sshapeArray = new Sshape*[mNbShape];
	// ****will probably have to stock the size of each row beforehand
	
	//loop on shape objects
	for (int i = 2; i < mNbShape; i++)
	{
		Sshape shapesFreemanCode;
		sshapeArray[i] = &shapesFreemanCode;
		
		string fileLineAssociatedToShape;
		getSpecificLine(fileFreeman, i, fileLineAssociatedToShape);
		

		shapesFreemanCode.setCoordX(fileLineAssociatedToShape[0]);
		shapesFreemanCode.setCoordY(fileLineAssociatedToShape[1]);
		shapesFreemanCode.setFreemanNumber(fileLineAssociatedToShape[2]);
		shapesFreemanCode.setCodeFreeman(readAssociatedFreemanCodeLine(fileLineAssociatedToShape, shapesFreemanCode.freemanNumber()));
		
	}

}

void Image::getSpecificLine(ifstream & textFile, int desiredLineOfFile, string & adresseOfFileLine)
{
	//static string stringToReturn;
	string tempStringToReturn;
	getline(textFile, tempStringToReturn);
	std::cout << textFile.gcount() << '\n';

	for (int i = 0; i <= desiredLineOfFile; i++)
	{
		if (i != desiredLineOfFile) 
		{
			getline(textFile, tempStringToReturn);
		}
		else
		{
			getline(textFile, tempStringToReturn);
			//put the value of the string at the corresponding adresse
			adresseOfFileLine = tempStringToReturn;
			break;
		}		
	}
}

int** Image::readAssociatedFreemanCodeLine(string line, int codeSize)
{
	// convert string values to int and put it in a int *
	int* freemanCode = new int[codeSize];
	for (int i = 0; i < codeSize; i++)
	{
		freemanCode[i] = convertCharToInt(line[i]);
	}
	
	return &freemanCode;
}