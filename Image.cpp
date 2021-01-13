#include "Image.h"


int Image::nbShape()
{
	return mNbShape;
}

int Image::nbLine()
{
	return mNbLine;
}

void Image::setNbShape(int nombre)
{
	mNbShape = nombre;
}

void Image::setNbLine(int nombre)
{
	mNbLine = nombre;
}

Image::Image()
{
}

Image::~Image()
{
}
