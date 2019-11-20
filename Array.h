#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include "Matrix.h"

class Matrix;
class Array
{
private:
	int *a;
	int n;
public:
	Array(int);
	~Array();
	Array(const Array &arr);
	Array &operator =(const Array &arr);
	void input();
	void output();
	friend void Matrix::Multi(Array &arr);
};
#endif // !ARRAY_H
