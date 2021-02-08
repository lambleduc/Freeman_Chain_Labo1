#include "Image.h"

int main() {
	char again = 'y';
	while (again == 'y')
	{
		Image image;
		cout << endl << "Do you want to read another file? [y/n]" << endl;
		cin >> again;
	}
	return 0;
}