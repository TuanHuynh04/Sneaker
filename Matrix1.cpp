#include "pch.h"
#include "Matrix1.h"
#include<iostream>
#include <istream>
#include <assert.h>
#include <ostream>

using namespace std;


int main() {/*
	Matrix1 matrix1(3, 4);
	matrix1.input();
	matrix1.output();
	matrix1.sumRow();
	matrix1.maxCol();
	cout << "Matrix after permutation:";
	matrix1.permutation(0,1);
	matrix1.output();
	matrix1.saddlePoint(); 
	*/
	Matrix1 matrix1(3, 2);
	cin >> matrix1;
	cout << matrix1;
	cout << endl;

	Matrix1 matrix2(3, 2);
	cin >> matrix2;
	cout << matrix2;

	Matrix1 matrix3 = matrix1 + matrix2;
	cout << matrix3;

	matrix3[1] = 1000;
	cout << matrix3;

	cout << matrix3[1];

}

Matrix1::Matrix1(int m,int n)
{
	this->m = m;
	this->n = n;
	a = new int*[m];
	for (int row = 0; row < this->m; row++)
		a[row] = new int[n];
}
Matrix1::Matrix1(const Matrix1 &matrix1) {
	this->m = matrix1.m;
	this->n = matrix1.n;
	//new dia chi moi cho a cua doi tuong this
	this->a = new int *[this->m];
	for (int row = 0; row < this->m; row++)
		this->a[row] = new int[this->n];

	//copy content from matrix to this
	for(int row=0;row<matrix1.m;row++)
		for(int col=0;col<matrix1.n;col++)
			this->a[row][col] = matrix1.a[row][col];
	
}
Matrix1 &Matrix1::operator=(const Matrix1 &matrix1) {
	this->m = matrix1.m;
	this->n = matrix1.n;
	this->a = new int *[this->m];
	for (int row = 0; row < this->m; row++)
		this->a[row] = new int[this->n];

	//copy content from matrix to this
	for (int row = 0; row < matrix1.m; row++)
		for (int col = 0; col < matrix1.n; col++)
			this->a[row][col] = matrix1.a[row][col];
	return *this;
}

Matrix1::~Matrix1()
{
	delete[]a;
	a = NULL;
}
istream &operator>>(istream &is, Matrix1 &m) {
	for (int row = 0; row < m.m; row++)
		for (int col = 0; col < m.n; col++)
		{
			cout << "Enter element [" << row << "][" << col << "]:";
			cin >> m.a[row][col];
		}
	return is;
}
ostream &operator<<(ostream &os, Matrix1 &m) {
	for (int row = 0; row < m.m; row++) {
		cout << endl;
		for (int col = 0; col < m.n; col++)
		{
			cout << m.a[row][col] << "  ";
		}
	}
	return os;
}
void Matrix1::sumRow() {
		for(int row=0;row<this->m;row++){
			int sum = 0;
			for (int col = 0; col < this->n; col++) {
				sum += a[row][col];
			}
			cout << "\n\tSum of Row " << row+1 << ":"<<sum<<endl;
	}
}
void Matrix1::maxCol() {
	for (int col = 0; col < this->n; col++) {
		int max = a[0][col];
		for (int row = 1; row < this->m; row++) {	
			if (max < a[row][col])
				max = a[row ][col];
		}
		cout << "\n\t\tMax of Col " << col + 1 << ":" << max << endl;
	}
}
void Matrix1::hoanvi(int &a,int &b) {
	int t = a;
	a = b;
	b = t;
}
void Matrix1::permutation(int h, int k) {
	if ((h >= 0 && h < this->m) && (k >= 0 && k < this->m)) {
		for (int col = 0; col < this->n; col++)
			hoanvi(a[h][col], a[k][col]);
	}
	else
		cout << "Out of index";
}
int Matrix1::maxCol1(int col) {
		int max = a[0][col];
		for (int row = 1; row < this->m; row++) {
			if (max < a[row][col])
				max = a[row][col];
		}
		return max;
}
int Matrix1::maxRow1(int row) {
		int max = a[row][0];
		for (int col = 1; col < this->n; col++) {
			if (max < a[row][col])
				max = a[row][col];
		}
		return max;
}
void Matrix1::saddlePoint() {
	int count = 0;
	for (int row = 0; row < this->m; row++) 
		for (int col = 0; col < this->n; col++) {
			if (maxRow1(row) == maxCol1(col))
			{
				cout << "\n\t" << a[row][col] << " la mot diem yen ngua";
				count++;
			}
		}
	if (count == 0) cout << "\nDon't have Saddlepoint";
}
Matrix1 Matrix1::operator+(Matrix1 matrix){
	Matrix1 matrix3(m,n);
	if (matrix.m == this->m && matrix.n == this->n) {
		for (int row = 0; row < this->m; row++)
			for (int col = 0; col < this->n; col++) {
				matrix3.a[row][col] = matrix.a[row][col] + this->a[row][col];
			}
		cout << "\nMATRIX 3 :" << endl;
		return matrix3;
	}
}
int &Matrix1::operator[](int index) {
	assert(0 <= index && index < n);
	return  *this->a[index];
}