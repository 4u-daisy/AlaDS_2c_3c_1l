#pragma once
#include <iostream>
#include <conio.h>
#include "matrix.h"
#include "collection.h"

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
		if (key == 27 || key >= 49 && key <= 54 || key == 75 || key == 77 || key == 13)
			return key;
	}
}
int menu_mathematical_operations() {
	while (true)
	{
		std::cout << "1. Add up matrices\n2. Subtract matrices\n3. Matrix multiplication\n4. Multiply the current matrix by a number.\n";
		std::cout << "5. Divide the current matrix by a number.\n6. Calculate the trace of the current matrix.\n\n7. Add matrix.\n";
		int key = get_key();
		if (key == 27 || key >= 49 && key <= 55 ||  key == 75 || key == 77 || key == 13)
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


template<typename T>
void input_correctly_number(T& numb) {
	do {
		std::cout << "\nInput number: ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> numb;
	} while (std::cin.fail());
}

void add_matrix(collection& cll) {
	system("cls");
	std::cout << "Please enter a number, not a string!\n";
	std::cout << "Input size matrix: N and M\n";
	int N = 0, M = 0;
	do {
		std::cout << "N >=0: ";
		input_correctly_number(N);
	} while (N < 0);
	do {
		std::cout << "M >=0: ";
		input_correctly_number(M);
	} while (M < 0);
	std::cout << "Input data in matrix:\n";
	double** data;
	data = new double* [N];
	for (int i = 0; i < N; i++) {
		data[i] = new double[M];
		for (int j = 0; j < M; j++) {
			std::cout << "Data[" << i << "][" << j << "] - ";
			input_correctly_number(data[i][j]);
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


void calculate_trace(collection& cll, const int ind) {
	if (cll._size == 0) {
		std::cout << "There are no matrices, let's add at least one!\n";
		int _key = _getch();
		add_need_matrix(cll);
	}
	std::cout << "Trace of the current matrix\nRESULT - ";
	std::cout << cll._array_mtrx[ind].matrix_trace();
	int key = _getch();
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
		if (choose == 27 || choose == 13) {
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
				calculate_trace(cll, ind);
			}
			else if (choose == 27 || choose == 13) {
				break;
			}
			else if (choose == 75 || choose == 77) {
				print_current(cll, ind, choose);
			}
			else if (choose >= 49 && choose <= 51) {
				res_binary_opeartion(cll, choose);
			}
			else if (choose == 55) {
				add_need_matrix(cll);
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