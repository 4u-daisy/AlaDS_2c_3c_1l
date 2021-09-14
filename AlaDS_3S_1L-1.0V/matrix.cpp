#include "matrix.h"
#include <iostream>

matrix::matrix() {
	_N = 0; 
	_M = 0;
	_data = NULL;
}
matrix::matrix(const int N, const int M, double** data) {
	_N = N;
	_M = M;
	_data = new double* [_N];
	for (int i = 0; i < _N; i++) {
		_data[i] = new double[_M];
		for (int j = 0; j < _M; j++) {
			_data[i][j] = data[i][j];
		}
	}
}
matrix::matrix(const matrix& rhs) : _N(rhs._N), _M(rhs._M), _data(rhs._data) {}


double** matrix::get_data() const
{
	return _data;
}
int matrix::get_N() const
{
	return _N;
}
int matrix::get_M() const
{
	return _M;
}

double& matrix::operator()(const int N, const int M)
{
	if (_N <= N || _M <= M)
		throw std::logic_error("error");
	return _data[N][M];
}
double matrix::operator()(const int N, const int M) const
{
	if (_N <= N || _M <= M)
		throw std::logic_error("error");
	return _data[N][M];
}
void matrix::operator=(const int i)
{
	if (i != NULL) {
		throw std::logic_error("error");
	}
	_data = NULL;
	_M = 0;
	_N = 0;

}
bool matrix::operator==(const int i)
{
	if (_data == NULL) {
		return false;
	}
	return true;
}
void matrix::operator=(const matrix& rhs) 
{
	_N = rhs._N;
	_M = rhs._M;
	_data = rhs._data;
}


matrix matrix::operator+(const matrix& rhs)
{
	if (_M != rhs._M || _N != rhs._N)
		throw std::logic_error("error");
	matrix c;
	c._N = _N;
	c._M = _M;
	c._data = new double*[c._N];

	for (int i = 0; i < c._N; i++) {
		c._data[i] = new double[c._M];
		for (int j = 0; j < c._M; j++) {
			c._data[i][j] = _data[i][j] + rhs._data[i][j];
		}
	}

	return c;
}
matrix matrix::operator-(const matrix& rhs)
{
	if (_M != rhs._M || _N != rhs._N)
		throw std::logic_error("error");
	matrix c;
	c._N = _N;
	c._M = _M;
	c._data = new double*[c._N];
	
	for (int i = 0; i < c._N; i++) {
		c._data[i] = new double[c._M];
		for (int j = 0; j < c._M; j++) {
			c._data[i][j] = _data[i][j] - rhs._data[i][j];
		}
	}
	return c;
}
matrix matrix::operator*(const matrix& rhs)
{
	if (_M != rhs._N)
		throw std::logic_error("error");

	matrix c;
	c._N = _N;
	c._M = rhs._M;
	c._data = new double*[c._N];

	for (int i = 0; i < _N; i++) {
		c._data[i] = new double[c._M];
		for (int j = 0; j < rhs._M; j++) {
			c._data[i][j] = 0;
			for (int k = 0; k < _M; k++) {
				c._data[i][j] += _data[i][k] * rhs._data[k][j];
			}
		}
	}
	return c;
}
matrix matrix::operator*(const int rhs)
{
	matrix c;
	c._N = _N;
	c._M = _M;
	c._data = new double*[c._N];
	for (int i = 0; i < _N; i++) {
		c._data[i] = new double[c._M];
		for (int j = 0; j < _M; j++) {
			c._data[i][j] = _data[i][j] * rhs;
		}
	}
	return c;
}
matrix matrix::operator/(const int rhs)
{
	matrix c;
	c._N = _N;
	c._M = _M;
	c._data = new double*[c._N];
	for (int i = 0; i < _N; i++) {
		c._data[i] = new double[c._M];
		for (int j = 0; j < _M; j++) {
			c._data[i][j] = _data[i][j] / rhs;
		}
	}
	return c;
}

bool matrix::operator==(const matrix& rhs)
{
	if (_N != rhs._N || _M != rhs._M || _data != rhs._data)
		return false;
	return true;
}
bool matrix::operator!=(const matrix& rhs)
{
	if (_N != rhs._N || _M != rhs._M || _data != rhs._data)
		return true;
	return false;
}
bool matrix::operator>=(const matrix& rhs)
{
	if (_M != rhs._M || _N != rhs._N)
		throw std::logic_error("error");
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (_data[i][j] < rhs._data[i][j])
				return false;
		}
	}
	return true;
}
bool matrix::operator<=(const matrix& rhs)
{
	if (_M != rhs._M || _N != rhs._N)
		throw std::logic_error("error");
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (_data[i][j] > rhs._data[i][j])
				return false;
		}
	}
	return true;
}
bool matrix::operator>(const matrix& rhs)
{
	if (_M != rhs._M || _N != rhs._N)
		throw std::logic_error("error");
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (_data[i][j] <= rhs._data[i][j])
				return false;
		}
	}
	return true;
}
bool matrix::operator<(const matrix& rhs)
{
	if (_M != rhs._M || _N != rhs._N)
		throw std::logic_error("error");
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			if (_data[i][j] >= rhs._data[i][j])
				return false;
		}
	}
	return true;
}


double matrix::matrix_trace() const
{
	if (_N != _M)
		throw std::logic_error("error");
	double res = 0;
	for (int i = 0; i < _N; i++) {
		res += _data[i][i];
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, const matrix& lhs)
{
	if (lhs._data != NULL) {
		for (int i = 0; i < lhs._N; i++) {
			for (int j = 0; j < lhs._M; j++) {
				out << lhs._data[i][j] << " ";
			}
			out << "\n";
		}
		return out;
	}
	else {
		out << "Matrix does not exist";
	}
}
std::istream& operator>>(std::istream& in, matrix& lhs)
{
	for (int i = 0; i < lhs._N; i++) {
		for (int j = 0; j < lhs._M; j++) {
			std::cout << "input data[" << i << "][" << j << "] - ";
			in >> lhs._data[i][j];
		}
	}
	return in;
}

