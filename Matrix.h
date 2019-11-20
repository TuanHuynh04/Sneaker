#pragma once
#ifndef MATRIX_H
#define MATRIX_H

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
	int sumMain();
	int sumSubline();
	int minSubline();
	int maxMain();
	void remove(int index);
	void spiral();
	const Matrix &operator[](int index) const;
	int &operator[](int index);

};
#endif // !MATRIX_H
