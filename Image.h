#pragma once
#define Image_H
#include <iostream>

using namespace std;

class Image
{
public:
	Image();
	~Image();
	int nbShape();
	int nbLine();
	//Check the setters' relevancy considering the initializer
	void setNbShape(int number);
	void setNbLine(int number);

private:
	int mNbShape;
	int mNbLine;
};
