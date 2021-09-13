#pragma once
#include <iostream>
#include <conio.h>
#include "matrix.h"
#include "collection.h"


/*
*
* Вывод матрицы
*
* 1. Работа с матрицами (вывести списком, добавить или удалить)
* 2. Математические операции
* 3. Помощь
* 4. Выход
*
*/

/*
*
* 1. Показать все матрицы в коллекции
* 2. Добавить матрицу в конец (ввод значений)
* 3. Добавить рандомную матрицу в конец
* 4. Удалить последнюю матрицу
* 5. Отредактировать все значения текущей матрицы
* 6. Отредактировать значение текущей матрицы по индексу
*
*/

/*
*
* 1. Сложить матрицы
* 2. Вычесть матрицы
* 3. Умножить матрицы
* 4. Умножить матрицу на число
* 5. Разделить матрицу на число
* 6. Вычислить след матрицы
*
*/

/*
*
* Вывод технической информации
*
*/


int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int menu_choose() {
	while (true)
	{
		std::cout << "1. Working with matrices (display a collection, add, delete).\n2. Mathematical operations.\n";
		std::cout << "3. Help.\n4. Exit.\n";
		std::cout << "Left arrow will show the previous matrix, right arrow will show the next matrix.\n";
		int key = get_key();
		if (key == 27 || key >= 49 && key <= 52 || key == 75 || key == 77)
			return key;
	}
}
int menu_working_with_matrix() {
	while (true)
	{
		std::cout << "1. Show all matrices in the collection\n2. Add a matrix to the end(entering values)\n3. Add a random matrix to the end\n";
		std::cout << "4. Remove the last matrix\n5. Edit all values of the current matrix\n6. Edit the value of the current matrix by index\nEsc exit\n";
		std::cout << "Left arrow will show the previous matrix, right arrow will show the next matrix.\n";
		int key = get_key();
		if (key == 27 || key >= 49 && key <= 54 || key == 75 || key == 77)
			return key;
	}
}
int menu_mathematical_operations() {
	while (true)
	{
		std::cout << "1. Add up matrices\n2. Subtract matrices\n3. Matrix multiplication\n4. Multiply the current matrix by a number.\n";
		std::cout << "5. Divide the current matrix by a number.\n6. Calculate the trace of the current matrix.\n";
		int key = get_key();
		if (key == 27 || key >= 49 && key <= 54 ||  key == 75 || key == 77)
			return key;
	}
}

void print_current(collection& cll, unsigned int& ind, const int choose) {
	if (choose == 75) {
		if (ind > 0)
			ind--;
		else
			ind = cll._size - 1;
	}
	if (choose == 77) {
		if (ind == cll._size - 1)
			ind = 0;
		else
			ind++;
	}
}

void add_matrix(collection& cll) {
	std::cout << "Input size matrix: N and M\nInput N: ";
	unsigned int N, M;
	std::cin >> N;
	std::cout << "\nInput M: ";
	std::cin >> M;
	std::cout << "Input data in matrix:\n";
	double** data;
	data = new double* [N];
	for (unsigned int i = 0; i < N; i++) {
		data[i] = new double[M];
		for (unsigned int j = 0; j < M; j++) {
			std::cout << "input data[" << i << "][" << j << "] - ";
			std::cin >> data[i][j];
		}
	}
	matrix v(N, M, data);
	cll.push_back(v);
}
void add_random_matrix(collection& cll) {
	unsigned int N, M;
	N = rand() % 4+1;
	M = rand() % 4+1;
	double** data;
	data = new double*[N];
	for (unsigned int i = 0; i < N; i++) {
		data[i] = new double[M];
		for (unsigned int j = 0; j < M; j++) {
			data[i][j] = rand() % 20;
		}
	}
	matrix v(N, M, data);
	cll.push_back(v);
	std::cout << v;
}
void change_data_matrix(collection& cll, const unsigned int ind) {
	int N, M;
	while (true) {
	std::cout << "Input correctly index: N and M\nInput N: ";
	std::cin >> N;
	std::cout << "\nInput M: ";
	std::cin >> M;
	if ((N >= 0 && N < cll._array_mtrx[ind].get_N()) && (M >= 0 && M < cll._array_mtrx[ind].get_M()))
		break;
	}
	int data;
	std::cout << "Input new data: ";
	std::cin >> data;
	cll._array_mtrx[ind](N, M) = data;
}

void add_need_matrix(collection& cll) {
	system("cls");
	std::cout << "Add a matrix.\n";
	int key = 0;
	while (true) {
		std::cout << "1. Add a random matrix.\n2. Add matrix with input values.\n";
		key = get_key();
		if (key == 49 || key == 50)
			break;
	}
	if (key == 49) {
		add_random_matrix(cll);
	}
	if (key == 50) {
		add_matrix(cll);
	}
	int _key = _getch();
}


void print_collection_matrix(const collection& cll) {
	for (unsigned int i = 0; i < cll._size; i++) {
		std::cout << "Matrix number " << i + 1 << '\n' << cll._array_mtrx[i] << "\n\n";
	}
}

/*
*
* 1. Вывести все доступные матрицы
* 2. Ввести новые матрицы
* 3. Выбрать первую матрицу
* 4. Выбрать вторую матрицу
* 
*/

int menu_choose_index(unsigned int a, unsigned int b)
{
	while (true)
	{
		system("cls");
		std::cout << "1. Display all available matrices.\n";
		std::cout << "Input the index of the matrix you want to work with\n";
		std::cout << "2. Select the first matrix.\n3. Select the second matrix.\n4. Add matrix\nPress to continue...\n";
		std::cout << "\nCurrently the first index - " << a << ", second - " << b << '\n';
		int key = get_key();
		if (key == 27 || key >= 49 && key <= 52 || key == 13)
			return key;
	}
}
void input_index(unsigned int& a, unsigned int size) {
	while (true) {
		std::cout << "Input the index of the matrix you want to work with: [1, " << size << "]\n";
		std::cin >> a;
		if (a > 0 && a <= size)
			break;
	}
}
void choose_index(collection& cll, unsigned int& a, unsigned int& b) {
	while (true) {
		int key = menu_choose_index(a, b);
		if (key == 27 || key == 13) {
			break;
		}
		if (key == 49) {
			print_collection_matrix(cll);
		}
		if (key == 50){
			input_index(a, cll._size);
		}
		if (key == 51) {
			input_index(b, cll._size);
		}
		if (key == 52) {
			add_need_matrix(cll);
		}
		int _key = get_key();
	}
}

void push_collection(collection& cll, matrix a) {
	int key = 0;
	while (true) {
		std::cout << "\nWant to add a result to your collection? If yes - input 1, else 2 ";
		key = get_key();
		if (key == 49 || key == 50)
			break;
	}
 	if (key == 49) {
		cll.push_back(a);
	}
}
void res_binary_opeartion(collection& cll, const int choose) {
	unsigned int a = 1, b = 1;
	if (cll._size == 1)
		add_need_matrix(cll);
	choose_index(cll, a, b);
	if (choose == 49) {
		std::cout << "\n\nRESULT\n\n "<< cll._array_mtrx[a-1] + cll._array_mtrx[b-1];
		push_collection(cll, cll._array_mtrx[a-1] + cll._array_mtrx[b-1]);
	}
	if (choose == 50) {
		std::cout << "\n\nRESULT\n\n " << cll._array_mtrx[a-1] - cll._array_mtrx[b-1];
		push_collection(cll, cll._array_mtrx[a-1] - cll._array_mtrx[b-1]);
	}
	if (choose == 51) {
		std::cout << "\n\nRESULT\n\n " << cll._array_mtrx[a-1] * cll._array_mtrx[b-1];
		push_collection(cll, cll._array_mtrx[a-1] * cll._array_mtrx[b-1]);
	}
}

void res_binary_numb_operation(collection& cll, const int choose, const int ind) {
	if (cll._size == 0) {
		std::cout << "There are no matrices, let's add at least one!\n";
		int _key = _getch();
		add_need_matrix(cll);
	}
	int numb = 0;
	std::cout << "\nOkay, input number: ";
	std::cin >> numb;
	if (choose == 52) {	
		std::cout << "\n\nRESULT\n\n " << cll._array_mtrx[ind] * numb;
		push_collection(cll, cll._array_mtrx[ind] * numb);
	}
	if (choose == 53) {
		std::cout << "\n\nRESULT\n\n " << cll._array_mtrx[ind] / numb;
		push_collection(cll, cll._array_mtrx[ind] / numb);
	}
}



void working_with_matrix(collection& cll, unsigned int ind) {
	while (true) {
		system("cls");
		std::cout << "Current matrix is:\n" << cll._array_mtrx[ind] << "\n";
		int choose = menu_working_with_matrix();
		if (choose == 49) {
			print_collection_matrix(cll);
			int key = get_key();
		}
		if (choose == 50) {
			add_matrix(cll);
			std::cout << "Success matrix added. Press any button to continue.\n";
			int key = get_key();

		}
		if (choose == 51) {
			add_random_matrix(cll);
			std::cout << "Success matrix added. Press any button to continue.\n";
			int key = get_key();
		}
		if (choose == 52) {
			if (ind == cll._size - 1 && ind != 0) {
				ind--;
			}
			cll.pop_back();
			std::cout << "Success matrix deleted. Press any button to continue.\n";
			
			int key = get_key();
		}
		if (choose == 53) {
			std::cin >> cll._array_mtrx[ind];
			std::cout << "Success matrix changed. Press any button to continue.\n";
			int key = get_key();
		}
		if (choose == 54) {
			change_data_matrix(cll, ind);
			std::cout << "Success matrix changed. Press any button to continue.\n";
			int key = get_key();
		}
		if (choose == 27) {
			break;
		}
		if (choose == 75 || choose == 77) {
			print_current(cll, ind, choose);
		}
	}
}
void mathematical_operations(collection& cll, unsigned int ind) {
	while (true) {
		try {
			system("cls");
			std::cout << "Current matrix is:\n" << cll._array_mtrx[ind] << "\n";
			int choose = menu_mathematical_operations();
			if (choose == 54) {
				if (cll._size == 0) {
					std::cout << "There are no matrices, let's add at least one!\n";
					int _key = _getch();
					add_need_matrix(cll);
				}
				std::cout << "Trace of the current matrix\nRESULT - ";
				std::cout << cll._array_mtrx[ind].matrix_trace();
				int key = _getch();
			}
			else if (choose == 27) {
				break;
			}
			else if (choose == 75 || choose == 77) {
				print_current(cll, ind, choose);
			}
			else if (choose >= 49 && choose <= 51) {
				res_binary_opeartion(cll, choose);
			}
			else {
				res_binary_numb_operation(cll, choose, ind);
			}
		}
		catch (std::exception& e) {
			std::cerr << "Caught: " << e.what() << std::endl;
			std::cerr << "Type: " << typeid(e).name() << std::endl;
			int key = get_key();
		}
	}
}


void edit_menu(collection& cll);
void help(collection& cll) {
	std::cout << "help";
	int key = _getch();
}
void edit_menu(collection& cll) {
	unsigned int ind = 0;

	while (true) {
		system("cls");
		std::cout << "Current matrix is:\n" << cll._array_mtrx[ind] << "\n";
		int choose = menu_choose();

		if (choose == 49) {
			working_with_matrix(cll, ind);
		}
		if (choose == 50) {
			mathematical_operations(cll, ind);
		}
		if (choose == 51) {
			help(cll);
		}

		if (choose == 75 || choose == 77) {
			print_current(cll, ind, choose);
		}
		if (choose == 27 || choose == 52) {
			break;
		}
	}
}