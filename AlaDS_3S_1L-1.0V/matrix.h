#pragma once
#include <iostream>

/*
Класс матриц вещественных чисел произвольного размера .
Как минимум, предоставить:
• конструктор с параметрами: размеры матрицы и значение для заполнения;
• оператор () для чтения/записи элемента матрицы по указанным индексам;
• операторы сложения и вычитания матриц;
• оператор умножения матриц;
• оператор умножения матрицы на скаляр (обеспечить коммутативность);
• оператор деления матрицы на скаляр;
• вычисление следа матрицы.
*/

/*
~matrix() {
	delete[] _data;
}
*/

class matrix {
private:
	double** _data;
	int _N, _M;

public:
	matrix();
	matrix(const int N, const int M, double** data);
	matrix(const matrix& rhs);

	double** get_data();

	double& operator()(const int N, const int M);
	double operator()(const int N, const int M) const;

	void operator=(const int i);

	void operator=(const matrix& rhs);
	matrix operator+(const matrix& rhs);
	matrix operator-(const matrix& rhs);
	matrix operator*(const matrix& rhs);
	matrix operator*(const int rhs);
	matrix operator/(const int rhs);

	bool operator==(const matrix& rhs);
	bool operator!=(const matrix& rhs);
	bool operator>=(const matrix& rhs);
	bool operator<=(const matrix& rhs);
	bool operator>(const matrix& rhs);
	bool operator<(const matrix& rhs);

	double matrix_trace() const;

	friend std::ostream& operator<<(std::ostream& out, const matrix& lhs);
	friend std::istream& operator>>(std::istream& in, matrix& lhs);

};