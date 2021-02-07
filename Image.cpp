#include "Image.h"


Image::Image()
	:
	mNbColumn{ 0 },
	mNbRow{ 0 },
	mNbShape{ 0 }
{
	readFreemanCodeFile("FreemanCode.txt");
	screenDisplay();
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

	//could be a problem here when we leave the function
	//Sshape** sshapeArray = new Sshape * [mNbShape];

	mSshapeArray = new Sshape * [mNbShape];
	for (int i = 0; i < mNbShape; i++)
	{
		mSshapeArray[i] = new Sshape();
		getline(fileFreeman, line);
		stockFreemanCodeInfos(*mSshapeArray[i], line);
	}
	fileFreeman.close();
	for (int i = 0; i < mNbShape; i++)
	{
		mSshapeArray[i]->displayCodeFreeman();
		printf("\n");
	}

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

void Image::stockFreemanCodeInfos(Sshape& shape, string line)
{
	// On s'intéresse à forme en tant que telles
	// start with a conversion of chars to int


	//create an array of Sshape

	// ****will probably have to stock the size of each row beforehand

	//loop on shape objects

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

	shape.setCoordX(convertCharToIntArray(line, xDigits, 0));
	shape.setCoordY(convertCharToIntArray(line, yDigits, xDigits + 1));
	shape.setFreemanNumber(convertCharToIntArray(line, freemanDigits, xDigits + yDigits + 2));
	readAssociatedFreemanCodeLine(shape, line, shape.freemanNumber(), INDEX_FREEMAN_START);
}

void Image::getSpecificLine(ifstream& textFile, int desiredLineOfFile, string& adresseOfFileLine)
{
	//static string stringToReturn;
	string tempStringToReturn;
	getline(textFile, tempStringToReturn);

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

void Image::readAssociatedFreemanCodeLine(Sshape& shapesFreemanCode, string line, int codeSize, int startFreeman)
{
	// convert string values to int and put it in a int *
	int* freemanCode = new int[codeSize];
	int j = 0;
	int i = 0;
	istringstream ss(line);
	string token;
	char value;
	while (getline(ss, token, ' ') && j < codeSize) {
		if (i > startFreeman) {
			value = token[0];
			freemanCode[j] = convertCharToInt(value);
			j++;
		}
		i++;
	}
	shapesFreemanCode.setCodeFreeman(freemanCode);

}

void Image::screenDisplay()
{
	for (int i = 0; i < mNbShape; i++)
	{
		mSshapeArray[i]->createPixels();
		for (int j = 0; j < mSshapeArray[i]->freemanNumber(); j++)
		{
			cout << mSshapeArray[i]->pixels()[j]->coordinates().x();
			cout << mSshapeArray[i]->pixels()[j]->coordinates().y();
			cout << endl;
		}
	}
	mergeShapes();
	writeToFile();
}

void Image::mergeShapes()
{
	bool insideShape = 0;
	mImageRows = new int* [mNbRow] {0};
	for (int i = 0; i < mNbRow; ++i) {
		mImageRows[i] = new int[mNbColumn] {0};
	}

	for (int i = 0; i < mNbShape; i++)
	{
		//array contenant les coordonnées les plus à gauche de chaque rangée pour chaque shape
		mSshapeArray[i]->leftBorder = new int[mNbRow];
		mSshapeArray[i]->rightBorder = new int[mNbRow];
		for (int k = 0; k < mNbRow; k++)
		{
			mSshapeArray[i]->leftBorder[k] = 10000;
			mSshapeArray[i]->rightBorder[k] = -1;
		}

		int nbPixels = mSshapeArray[i]->nbPixels();
		for (int j = 0; j < nbPixels; j++)
		{
			int x = mSshapeArray[i]->pixels()[j]->coordinates().x();
			int y = mSshapeArray[i]->pixels()[j]->coordinates().y();
			if (mSshapeArray[i]->pixels()[j]->isStartingPoint())
				mImageRows[x][y] = 2;
			else
				mImageRows[x][y] = 1;
			if (mSshapeArray[i]->leftBorder[y] > x)
				mSshapeArray[i]->leftBorder[y] = x;
			if (mSshapeArray[i]->rightBorder[y] < x)
				mSshapeArray[i]->rightBorder[y] = x;

		}

		/*for (int k = 0; k < mNbRow; k++)
		{
			mSshapeArray[i]->leftBorder[k] = 10000;
			mSshapeArray[i]->rightBorder[k] = -1;
			for (int l = 0; l < mNbColumn; l++)
			{
				if (mImageRows[k][l] > 0 && mSshapeArray[i]->leftBorder[k] > l)
					mSshapeArray[i]->leftBorder[k] = l;
				if (mImageRows[k][l] > 0 && mSshapeArray[i]->rightBorder[k] < l)
					mSshapeArray[i]->rightBorder[k] = l;
			}
		}*/
		for (int k = 0; k < mNbRow; k++)
		{
			for (int l = 0; l < mNbColumn; l++)
			{
				if ((l > mSshapeArray[i]->leftBorder[k]) && (l < mSshapeArray[i]->rightBorder[k]))
				{
					mImageRows[l][k] = 1;
					mSshapeArray[i]->setAire(mSshapeArray[i]->Aire() + 1);
				}
			}
		}
		mSshapeArray[i]->calculatePerimeter();
		mSshapeArray[i]->setAire(mSshapeArray[i]->Aire() + mSshapeArray[i]->freemanNumber());
	}




	for (int i = 0; i < mNbRow; i++)
	{
		for (int j = 0; j < mNbColumn; j++)
		{
			printf("%d", mImageRows[i][j]);
		}
	}
}
void Image::writeToFile() {
	ofstream freemanFile;
	freemanFile.open("test3.txt");
	for (int i = 0; i < mNbRow; i++)
	{
		for (int j = 0; j < mNbColumn; j++)
		{
			if (i == 0 || i == mNbRow - 1) {
				freemanFile << "%";
			}
			else if (j == 0 || j == mNbColumn - 1) {
				freemanFile << "%";
			}
			else {
				switch (mImageRows[i][j]) {
				case 0:
					freemanFile << " ";
					break;
				case 1:
					freemanFile << "*";
					break;
				case 2:
					freemanFile << "X";
					break;
				}
			}
		}
		freemanFile << std::endl;
	}
	freemanFile << std::endl << "Il y a " << mNbShape << " objets dans l'image" << std::endl;
	for (int j = 0; j < mNbShape; j++)
	{
		freemanFile << "Objet no. " << j << " : Perimetre = " << mSshapeArray[j]->Perimetre() << "   Aire = " << mSshapeArray[j]->Aire() << std::endl; 
	}
	freemanFile.close();
}