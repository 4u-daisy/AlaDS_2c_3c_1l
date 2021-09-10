#include "Header.h"

m::m()
{
	_N = 0;
	_M = 0;
	_data = NULL;
}

m::m(const int N, const int M, double** data)
{
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

m::~m()
{
	delete[] _data;
}

double& m::operator()(const int N, const int M)
{
	if (_N <= N || _M <= M)
		throw std::logic_error("error");
	return _data[N][M];
}

m operator+(const m& lhs, const m& rhs)
{
	if (lhs._M != rhs._M || lhs._N != rhs._N)
		throw std::logic_error("error");
	m c;
	c._N = lhs._N;
	c._M = lhs._M;
	c._data = new double*[c._N * c._M];
	for (int i = 0; i < lhs._N; i++) {
		for (int j = 0; j < lhs._M; j++) {
			c._data[i][j] = lhs._data[i][j] + rhs._data[i][j];
		}
	}
	return c;
}

m operator-(const m& lhs, const m& rhs)
{
	if (lhs._M != rhs._M || lhs._N != rhs._N)
		throw std::logic_error("error");
	m c;
	c._N = lhs._N;
	c._M = lhs._M;
	c._data = new double* [c._N * c._M];
	for (int i = 0; i < lhs._N; i++) {
		for (int j = 0; j < lhs._M; j++) {
			c._data[i][j] = lhs._data[i][j] - rhs._data[i][j];
		}
	}
	return c;
}

std::ostream& operator<<(std::ostream& out, const m& lhs)
{
	for (int i = 0; i < lhs._N; i++) {
		for (int j = 0; j < lhs._M; j++) {
			out << lhs._data[i * lhs._N + j] << " ";
		}
		out << "\n";
	}
	return out;
}
