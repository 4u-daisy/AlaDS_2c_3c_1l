//#include <iostream>
//#include <conio.h>
//#include "matrix.h"
//#include "collection.h"

#include "interface.h"git 

int main() {

	collection cll;
	matrix tmp;
	cll.push_back(tmp);
	cll.pop_back();

	edit_menu(cll);

	for (int i = 0; i < cll._array_mtrx[i].get_M(); i++) {
		delete[] cll._array_mtrx[i].get_data();
	}
	delete[] cll._array_mtrx;

	return 0;
}
