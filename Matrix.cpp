#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Matrix::Matrix(int n)
{
	this->n = n;
	a = new int *[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
}
Matrix::Matrix(const Matrix &matrix) {
	//new dia chi moi cho a cua doi tuong this
	this->n = matrix.n;
	this->a = new int *[this->n];
	for (int i = 0; i < n; i++)
		this->a[i] = new int[this->n];

	//copy content from matrix to this
	for (int i = 0; i < matrix.n; i++)
		for (int j = 0; j < matrix.n; j++)
			this->a[i][j] = matrix.a[i][j];
}
Matrix &Matrix::operator=(const Matrix &matrix) {
	this->n = matrix.n;
	this->a = new int *[this->n];
	for (int i = 0; i < n; i++)
		this->a[i] = new int[this->n];

	//copy content from matrix to this
	for (int i = 0; i < matrix.n; i++)
		for (int j = 0; j < matrix.n; j++)
			this->a[i][j] = matrix.a[i][j];

	return *this;
}

Matrix::~Matrix()
{
	delete[]a;
	a = NULL;
}
void Matrix::input() {
	cout <<"Enter Matrix"<<endl;
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
		{
			cout << "\tEnter element [" << i << "][" << j << "]:";
			 a[i][j] = rand() % 10 + 1;
			 cout << a[i][j]<<endl;
		}
}
void Matrix::output() {
	cout << "Matrix";
	for (int i = 0; i < this->n; i++) {
		cout << endl;
		for (int j = 0; j < this->n; j++)
		{
			cout << a[i][j] << "	";
		}
	}
}