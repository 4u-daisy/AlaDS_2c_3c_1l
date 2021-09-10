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
	double** _data;
	int _N, _M;

public:
	matrix();
	matrix(const int N, const int M, double** data);
	matrix(const matrix& rhs);

	double& operator()(const int N, const int M);
	double operator()(const int N, const int M) const;

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