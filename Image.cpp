#include "Image.h"


Image::Image()
	:
	mNbColumn{ 0 },
	mNbRow{ 0 },
	mNbShape{ 0 }
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

	int rowDigits = 0;
	int columnDigits = 0;
	int shapeDigits = 0;
	getline(fileFreeman, line);
	//not really sexy ...
	while (line[rowDigits] != ' ') {
		rowDigits++;
	}
	mNbRow = convertCharToIntArray(line, rowDigits, 0);

	/*	Here, we simply state that the number of digits in our column coordinate will be equal to the length of the line minus the number
		of digits in our row coordinate, minus the "space" digit*/
	columnDigits = line.size() - rowDigits - 1;

	//From here on, work in progress still
	mNbColumn = convertCharToIntArray(line, columnDigits, rowDigits + 1);
	getline(fileFreeman, line);
	while (line[shapeDigits] != '\0') {
		shapeDigits++;
	}

	mNbShape = convertCharToIntArray(line, shapeDigits, 0);


	Sshape** sshapeArray = new Sshape * [mNbShape];
	for (int i = 0; i < mNbShape; i++)
	{
		getline(fileFreeman, line);
		sshapeArray[i] = stockFreemanCodeInfos(line);
	}

	for (int i = 0; i < mNbShape; i++)
	{
		sshapeArray[i]->displayCodeFreeman();
		printf("\n");
	}
	fileFreeman.close();
}

int Image::convertCharToInt(char charact)
{
	return (int)charact - '0';
}

int Image::convertCharToIntArray(string line, int length, int startDigit)
{
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += (((int)line[i + startDigit]) - (int)'0') * pow(10, length - 1 - i);
	}
	return sum;
}

Sshape* Image::stockFreemanCodeInfos(string line)
{
	// On s'intéresse à forme en tant que telles
	// start with a conversion of chars to int


	//create an array of Sshape

	// ****will probably have to stock the size of each row beforehand

	//loop on shape objects

	Sshape shapesFreemanCode;
	int xDigits = 0;
	int yDigits = 0;
	int freemanDigits = 0;
	while (line[xDigits] != ' ') {
		xDigits++;
	}
	while (line[xDigits + 1 + yDigits] != ' ') {
		yDigits++;
	}
	while (line[xDigits + yDigits + 2 + freemanDigits] != ' ') {
		freemanDigits++;
	}
	
	shapesFreemanCode.setCoordX(convertCharToIntArray(line, xDigits, 0));
	shapesFreemanCode.setCoordY(convertCharToIntArray(line, yDigits, xDigits + 1));
	shapesFreemanCode.setFreemanNumber(convertCharToIntArray(line, freemanDigits, xDigits + yDigits + 2));
	shapesFreemanCode.setCodeFreeman(readAssociatedFreemanCodeLine(line, shapesFreemanCode.freemanNumber(), xDigits+yDigits+freemanDigits+3));


	return &shapesFreemanCode;
}

void Image::getSpecificLine(ifstream& textFile, int desiredLineOfFile, string& adresseOfFileLine)
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

int** Image::readAssociatedFreemanCodeLine(string line, int codeSize, int startFreeman)
{
	// convert string values to int and put it in a int *
	int* freemanCode = new int[codeSize * 2 - 1];
	int j = 0;
	for (int i = startFreeman; i < ((codeSize*2-1)+startFreeman); i++)
	{
		if(i%2!=0){
			freemanCode[j] = convertCharToInt(line[i]);
			j++;
		}
	}

	return &freemanCode;
}