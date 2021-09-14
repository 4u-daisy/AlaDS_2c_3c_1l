#pragma once
#include <iostream>
#include <conio.h>
#include "matrix.h"
#include "collection.h"

int get_key();

int main_menu();
int menu_working_with_matrix();
int menu_mathematical_operations();

void print_current(collection& cll, unsigned int& ind, const int choose);

template<typename T>
void input_correctly_number(T& numb);

void add_matrix_with_input_values(collection& cll);
void add_random_matrix(collection& cll);
void change_data_current_matrix(collection& cll, const unsigned int ind);

void add_matrix(collection& cll);

void print_collection_matrix(const collection& cll);

int menu_choose_index(unsigned int a, unsigned int b);
void enter_the_desired_index_matrix(unsigned int& a, unsigned int size);
void choose_matrix(collection& cll, unsigned int& a, unsigned int& b);

void push_collection(collection& cll, matrix a);
void res_binary_matrix_opeartion(collection& cll, const int choose);

void res_binary_numb_operation(collection& cll, const int choose, const int ind);


void calculate_trace(collection& cll, const int ind);

void working_with_matrix(collection& cll, unsigned int ind);
void mathematical_operations(collection& cll, unsigned int ind);


void help(collection& cll);

void edit_menu(collection& cll);
