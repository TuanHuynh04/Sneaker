#include "pch.h"
#include "Array.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

Array::Array(int n)
{
	this->n = n;
	a = new int[n];
}
Array::Array(const Array &arr) {
	this->n = arr.n;
	this->a = new int[10];
	for (int i = 0; i < this->n; i++)
		this->a[i] = arr.a[i];
}
Array &Array::operator=(const Array &arr) {
	this->n = arr.n;
	this->a = new int[10];
	for (int i = 0; i < this->n; i++)
		this->a[i] = arr.a[i];
	return *this;
}
void Array::input() {
	cout << "\nEnter Array" << endl;
	for (int i = 0; i < this->n; i++) {
		cout << "\ta[" << i << "]:";
		cin >> a[i];
	}
}
void Array::output() {
	cout << "Array {";
	for (int i = 0; i < this->n; i++) {
		cout << a[i] << " ";
	}
	cout << "\b}";
}
Array::~Array()
{
	delete[]a;
	a = NULL;
}
