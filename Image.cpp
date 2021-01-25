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
		char n = ' ';
		int tailleRow = 0;
		switch (lineIterator)
		{
		case 0:
			while (line[tailleRow] != n) {
				tailleRow++;
			}
			for (int i = 0; i < tailleRow; i++) {
				mNbRow += ((int)line[i]-'0')* pow(10, tailleRow-1-i);
				printf("%d \n",mNbRow);
			}


			/*int firstNumber = line[0];
			int secondNumber = line[1];
			mNbRow = firstNumber * 10 + secondNumber;*/
			//not really sexy ...
			//mNbRow = (int) mNbRow - 48;
			mNbColumn = line[1];
			mNbColumn = (int) mNbColumn - 48;
			break;
		case 1:
			mNbShape = line[0];
			mNbShape = (int)mNbShape - 48;
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

void Image::stockFreemanCodeInfos(char & completeStringFile)
{
	// start with a conversion of chars to int


	//create an array of Sshape
	Sshape** sshapeArray = new Sshape*[mNbShape];
	// ****will probably have to stock the size of each row beforehand
	
	//loop on shape objects
	for (int i = 0; i < mNbShape; i++)
	{
		Sshape shapesFreemanCode;
		sshapeArray[i] = &shapesFreemanCode;
		shapesFreemanCode.setCoordX();
		shapesFreemanCode.setCoordY();
		shapesFreemanCode.setFreemanNumber();
		shapesFreemanCode
		
	}

}

void Image::createShape()
{
	Sshape shape;
	//shape.coordX =  
}

