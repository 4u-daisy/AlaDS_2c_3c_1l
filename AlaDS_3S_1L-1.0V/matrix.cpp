#include "matrix.h"
#include <iostream>

matrix::matrix() {
	_N = 0; 
	_M = 0;
	_data = NULL;
}
matrix::matrix(const int N, const int M, const double* data) {
	_N = N;
	_M = M;
	_data = new double [_N * _M];
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			_data[_N * i + j] = data[_N * i + j];
		}
	}
}
matrix::matrix(const matrix& rhs) : _N(rhs._N), _M(rhs._M), _data(rhs._data) {}

double& matrix::operator()(const int N, const int M)
{
	if (_N <= N || _M <= M)
		throw std::logic_error("error");
	return _data[_M * N + M];
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
	c._data = new double[c._N * c._M];

	for (int i = 0; i < c._N * c._M; i++) {
		c._data[i] = _data[i] + rhs._data[i];
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
	c._data = new double[c._N * c._M];
	
	for (int i = 0; i < _N * _M; i++) {
		c._data[i] = _data[i] - rhs._data[i];
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
	c._data = new double[c._N * c._M];

	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < rhs._M; j++) {
			c._data[i * _N + j] = 0;
			for (int k = 0; k < rhs._N; k++) {
				c._data[i * _N + j] += _data[k] * rhs._data[j + k * _M];
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
	c._data = new double[c._N * c._M];
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			c._data[_N * i + j] = _data[_N * i + j] * rhs;
		}
	}
	return c;
}
matrix matrix::operator/(const int rhs)
{
	matrix c;
	c._N = _N;
	c._M = _M;
	c._data = new double[c._N * c._M];
	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _M; j++) {
			c._data[_N * i + j] = _data[_N * i + j] / rhs;
		}
	}
	return c;
}
double matrix::matrix_trace() const
{
	if (_N != _M)
		throw std::logic_error("error");
	double res = 0;
	for (int i = 0; i < _N; i++) {
		res += _data[i * _N + i];
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, const matrix& lhs)
{
	for (int i = 0; i < lhs._N; i++) {
		for (int j = 0; j < lhs._M; j++) {
			out << lhs._data[i * lhs._N + j] << " ";
		}
		out << "\n";
	}
	return out;
}
