#pragma once
#include <utility>
#include <iostream>

class matrix {
private:
	double** _data;
	int _N, _M;

public:
	matrix();
	matrix(const int N, const int M);
	matrix(const matrix& rhs);

	void swap(matrix& rhs) {
		std::swap(_N, rhs._N);
		std::swap(_M, rhs._M);
		std::swap(_data, rhs._data);

	}

	~matrix() {
		for (int i = 0; i < _N; i++) {
			delete[] _data[i];
		}
		delete[] _data;
	}

	int get_N() const;
	int get_M() const;

	double& operator()(const int N, const int M);
	double operator()(const int N, const int M) const;

	void operator=(const int i);
	bool operator==(const int i);

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