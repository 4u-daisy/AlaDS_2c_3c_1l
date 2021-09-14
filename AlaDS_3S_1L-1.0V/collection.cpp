#include "collection.h"

void collection::push_back(matrix& a)
{
	if (_size % 10 == 0 || _size == 0) {
		collection cll(_array_mtrx, _size);
		_size += 10;
		_array_mtrx = new matrix[_size];
		_size -= 10;
		for (unsigned int i = 0; i < _size; i++) {
			_array_mtrx[i] = cll._array_mtrx[i];
		}
	}

	matrix tmp(a);
	_array_mtrx[_size] = tmp;
	_size++;
}

void collection::pop_back()
{
	if (_size != 0)
		_size -= 1;
	_array_mtrx[_size] = NULL;
}

std::ostream& operator<<(std::ostream& out, const collection& lhs)
{
	for (unsigned int i = 0; i < lhs._size; i++) {
		std::cout << lhs._array_mtrx[i];
		out << '\n';
	}
	return out;
}
