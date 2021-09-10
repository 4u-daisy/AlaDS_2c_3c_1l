#include <iostream>
#include "matrix.h"


/*
a - N = 2, M = 3
b - N = 3, M = 3
*/

int main() {

	double* a_data;
	double* b_data;


	a_data = new double[4];
	b_data = new double[4];

	for (int i = 0; i < 4; i++) {
		a_data[i] = i;
	}
	for (int i = 0; i < 4; i++) {
		b_data[i] = i;
	}

	matrix a(2, 2, a_data);
	matrix b(2, 2, b_data);


	a(0, 1) = -9;

	try {

		std::cout << a << '\n';
		std::cout << b << '\n';


		matrix c = a * b;

		std::cout << c << '\n';

		/*std::cout << a.matrix_trace() << '\n';
		b = (a / 10) * 3;
		std::cout << b << '\n';*/

	}
	catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
		std::cerr << "Type: " << typeid(e).name() << std::endl;
	}

	return 0;
}