#pragma once
#ifndef MATRIX_H
#define MATRIX_H

class Array;
class Matrix
{
private:
	int n;
	int **a;
public:
	Matrix(int);
	~Matrix();
	Matrix(const Matrix &);
	Matrix &operator=(const Matrix &);
	void input();
	void output();
	void Multi(Array &arr);
};
#endif // !MATRIX_H
