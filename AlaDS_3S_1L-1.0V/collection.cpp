#include "collection.h"

collection::~collection()
{
	delete[] _array_mtrx->get_data();
}

void collection::push_back(matrix& a)
{
	if (_size % 10 == 0 || _size == 0) {
		_size += 10;
		_array_mtrx = new matrix[_size];
		_size -= 10;
	}
	matrix tmp(a);
	_array_mtrx[_size] = tmp;
	_size++;
}

void collection::pop_back()
{
	_size -= 1;
	_array_mtrx[_size] = NULL;
}

std::ostream& operator<<(std::ostream& out, const collection& lhs)
{
	for (int i = 0; i < lhs._size; i++) {
		std::cout << lhs._array_mtrx[i];
		out << '\n';
	}
	return out;
}
