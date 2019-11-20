// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Matrix.h"
#include <istream>
#include <assert.h>
#include <ostream>

using namespace std;
/*
int main() {
	Matrix matrix(4);
	matrix.input();
	matrix.output();
	matrix.spiral();
	
	cout << endl;
	cout << "Matrix after remove at index";
	matrix.remove(2);
	matrix.output();
	
}*/

int &Matrix::operator[](int index) {
	assert(0 <= index && index < n);
	return *a[index];
}
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
	for(int i=0;i<matrix.n;i++)
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
	for (int i = 0; i < this->n; i++)
		for (int j = 0; j < this->n; j++)
		{
			cout << "Enter element [" << i << "][" << j << "]:";
			cin >> a[i][j];
		}
}
void Matrix::output() {
	for (int i = 0; i < this->n; i++) {
		cout << endl;
		for (int j = 0; j < this->n; j++)
		{
			cout << a[i][j] <<"	";
		}
	}
}
int Matrix::sumMain() {
	int sum = 0;
	for (int i = 0; i < this->n; i++)
		sum += a[i][i];
	return sum;
}
int Matrix::sumSubline() {
	int sum = 0;
	for(int i=0;i<this->n;i++)
		for (int j = 0; j < this->n; j++) {
			if ((i + j) == n - 1)
				sum += a[i][j];
		}
	return sum;
}
/*
int Matrix::minSubline() {
	int min;
	for(int i=0;i<this->n;i++)
		for (int j = 0; j < this->n; j++) {
			if ((i + j) == n - 1)
				if (min > a[i][j] && a[i][j] %2!=0 && min%2!=0)
					min = a[i][j];
		}
	return min;
}
*/
void Matrix::remove(int index) {
	for (int i = 0; i < this->n; i++) {
		for (int col = index; col < this->n - 1; col++)
			a[i][col] = a[i][col + 1];
	}
	for (int i = 0; i < this->n; i++) {
		for (int row = index; row < this->n - 1; row++)
			a[row][i] = a[row + 1][i];
	}
	this->n--;
}
void Matrix::spiral() {
	int left = 0, top = 0, count = 0;
	int right = n,bottom = n;
	int number = n * n;
	while (count < number) {//trai qua phai
		for (int i = left; i < right; i++) {
			if (a[top][i] == (count + 1)) {
				count++;
			}
		}
		top++;
		//tren xuong duoi
		for (int i = top; i < bottom; i++) {
			if (a[i][right - 1] == (count + 1)) {
				count++;
			}
		}
		right--;
		//phai sang trai
		for (int i = right - 1; i >= left; i--) {
			if (a[bottom - 1][i] == (count + 1)) {
				count++;
			}
		}
		bottom--;
		//duoi len tren
		for (int i = bottom - 1; i >= top; i--) {
			if (a[i][left] == (count + 1)) {
				count++;
			}
		}
		left++;
	}
	cout << count;
	if (count == number) {
		cout << "\nMatrix is spiral";
	}
	else
		cout << "\nMatrix is not spiral";
}

