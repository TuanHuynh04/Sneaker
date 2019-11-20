#include "pch.h"
#include "Array.h"
#include "Matrix.h"
#include <iostream>

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
	cout << "Enter Matrix" << endl;
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
		{
			cout << "\tEnter element [" << i << "][" << j << "]:";
			cin >> a[i][j];
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
void Matrix::Multi(Array &arr) {
	Array arr1(3);
	for (int i = 0; i < arr.n; i++) {
		arr1.a[i] = 0;
		for (int j = 0; j < this->n; j++) {
			arr1.a[i] = arr1.a[i] + this->a[i][j] * arr.a[i];
		}
	}
	cout << endl;
	arr1.output();
}