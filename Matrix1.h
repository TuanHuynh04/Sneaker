#pragma once
#ifndef MATRIX1_H
#define MATRIX1_H
#include <istream>
#include <ostream>

using namespace std;

class Matrix1
{
private:
	int **a;
	int m,n;
public:
	Matrix1(int,int);
	Matrix1(const Matrix1 &);
	Matrix1 &operator=(const Matrix1 &);
	~Matrix1();
	friend istream &operator>>(istream &is, Matrix1 &m);
	friend ostream &operator<<(ostream &os, Matrix1 &m);
	void sumRow();
	void maxCol();
	void hoanvi(int &,int &);
	void permutation(int,int);
	int maxRow1(int);
	int maxCol1(int);
	void saddlePoint();
	Matrix1 operator+(Matrix1 matrix);
	const Matrix1 &operator[](int index) const;
	int &operator[](int index);

};
#endif // !MATRIX1_H
