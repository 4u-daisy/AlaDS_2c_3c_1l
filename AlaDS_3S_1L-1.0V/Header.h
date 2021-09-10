#pragma once
#include <iostream>

class m {
private:
	double** _data;
	int _N, _M;

public:
	m();
	m(const int N, const int M, double** data);
	~m();

	double& operator()(const int N, const int M);

	friend m operator+(const m& lhs, const m& rhs);
	friend m operator-(const m& lhs, const m& rhs);
	//friend m operator*(const m& lhs, const m& rhs);
	//friend m operator*(const m& lhs, const int rhs);
	//friend m operator/(const m& lhs, const int rhs);

	//double matrix_trace() const;

	friend std::ostream& operator<<(std::ostream& out, const m& lhs);

};