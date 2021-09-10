#include <iostream>
#include "matrix.h"




int main() {

	const int N = 2, M = 2;
	const int NB = 2, MB = 2;
	double** arr_one = new double* [N];
	double** arr_two = new double* [NB];


	for (int i = 0; i < N; i++) {
		arr_one[i] = new double[M];
		for (int j = 0; j < M; j++) {
			arr_one[i][j] = rand() % 20;
		}
	}
	for (int i = 0; i < NB; i++) {
		arr_two[i] = new double[MB];

		for (int j = 0; j < MB; j++) {
			arr_two[i][j] = rand() % 20;
		}
	}

	matrix a(N, M, arr_one);
	matrix b(NB, MB, arr_two);

	try {

		std::cout << a << '\n';
		std::cout << b << '\n';

		/*matrix c = a * b;

		std::cout << c << '\n';

		std::cout << c*a << '\n';

		std::cout << c.matrix_trace() << '\n';

		std::cout << c << '\n';*/

		bool flag = a > b;

		std::cout << flag << '\n';

		a(0, 1) = 155;
		std::cout << a << '\n';

	}
	catch (std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
		std::cerr << "Type: " << typeid(e).name() << std::endl;
	}

	return 0;
}