#pragma once
#include <iostream>

/*
����� ������ ������������ ����� ������������� ������� .
��� �������, ������������:
� ����������� � �����������: ������� ������� � �������� ��� ����������;
� �������� () ��� ������/������ �������� ������� �� ��������� ��������;
� ��������� �������� � ��������� ������;
� �������� ��������� ������;
� �������� ��������� ������� �� ������ (���������� ���������������);
� �������� ������� ������� �� ������;
� ���������� ����� �������.
*/

/*
~matrix() {
	delete[] _data;
}
*/

class matrix {
private:
	double* _data;
	int _N, _M;

public:
	matrix();
	matrix(const int N, const int M, const double* data);
	matrix(const matrix& rhs);

	double& operator()(const int N, const int M);

	void operator=(const matrix& rhs);
	matrix operator+(const matrix& rhs);
	matrix operator-(const matrix& rhs);
	matrix operator*(const matrix& rhs);
	matrix operator*(const int rhs);
	matrix operator/(const int rhs);

	double matrix_trace() const;

	friend std::ostream& operator<<(std::ostream& out, const matrix& lhs);

};