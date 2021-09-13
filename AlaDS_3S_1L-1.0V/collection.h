#pragma once
#include "matrix.h"
#include <iostream>

class collection {
public:
	matrix* _array_mtrx;
	unsigned int _size;

	collection(): _array_mtrx(NULL), _size(0) {}
	collection(collection& copied) : _array_mtrx(copied._array_mtrx), _size(copied._size) {}
	collection(matrix* array_mtrx, const unsigned int size) : _array_mtrx(array_mtrx), _size(size) {}

	void push_back(matrix& a);
	void pop_back();

	friend std::ostream& operator<<(std::ostream& out, const collection& lhs);

};