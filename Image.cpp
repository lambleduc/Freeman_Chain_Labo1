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
		int tailleRow = 0;
		int tailleColumn = 0;
		switch (lineIterator)
		{
		case 0:
			//not really sexy ...
			while (line[tailleRow] != ' ') {
				tailleRow++;
			}
			for (int i = 0; i < tailleRow; i++) {
				mNbRow += ((int)line[i] - '0')* pow(10, tailleRow-1-i);
			}
		/*	Here, we simply state that the number of digits in our column coordinate will be equal to the length of the line minus the number
			of digits in our row coordinate, minus the "space" digit*/
			tailleColumn = line.size() - tailleRow - 1;

			//From here on, work in progress still
			for (int i = 0; i < tailleColumn; i++) {
				mNbColumn += ((int)line[i] - '0') * pow(10, tailleColumn - 1 - i);
			}
			break;
		case 1:
			mNbShape = line[0];
			mNbShape = (int)mNbShape - 48;
			break;
		}
		lineIterator++;
		std::cout << line << '\n';
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

void Image::stockFreemanCodeInfos(ifstream fileFreeman)
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
		shapesFreemanCode.setCodeFreeman(readAssociatedFreemanCodeLine(fileFreeman, i), );
		
	}

}

void Image::getSpecificLine(ifstream textFile, int desiredLineOfFile, string & adresseOfFile)
{
	//static string stringToReturn;
	string tempStringToReturn;

	for (int i = 0; i <= desiredLineOfFile; i++)
	{
		if (i != desiredLineOfFile) 
		{
			continue;
		}
		else
		{
			getline(textFile, tempStringToReturn);
			//put the value of the string at the corresponding adresse
			adresseOfFile = tempStringToReturn;
			break;
		}		
	}
}

int* Image::readAssociatedFreemanCodeLine(ifstream freemanCodeLine, int fileLine)
{
	string stringLine;
	
	
	return wholeFreemanCodeLine;
}

void Image::createShape()
{
	Sshape shape;
	//shape.coordX =  
}

