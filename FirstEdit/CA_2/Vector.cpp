#include <iostream>
#include "Vector.h"

Vector::Vector() {

}

Vector::Vector(int n) {

	this->data = new double[C * n];
	for (int i = 0; i < n; ++i) {
		this->data[i] = 0;
	}
	this->capacity = C * n;
	this->size = n;
}

Vector::~Vector() {

	delete[] this->data;
}

Vector::Vector(const Vector& v) {

	this->resize(v.size);
	for (int i = 0; i < this->size; ++i) {
		this->data[i] = v.data[i];
	}
}

void Vector::resize(int newSize) {

	int result = newSize > this->size ? this->size : newSize;
	if (newSize < this->capacity) {
		this->size = newSize;
	}
	else {
		double* data_copy = new double[C * newSize];
		for (int i = 0; i < result; ++i) {
			data_copy[i] = this->data[i];
		}
		delete[] this->data;
		this->data = data_copy;
		this->capacity = C * newSize;
		this->size = newSize;
	}
}

void Vector::push_back(int k){

	if (this->size == this->capacity) {
		resize(this->size + 1);
		this->data[this->size - 1] = k;
	}
	else {
		this->data[this->size] = k;
		this->size++;
	}
}

double Vector::pop_back(){

	double tmp = this->data[this->size];
	this->size--;

	return tmp;
}

void Vector::print(){

	for (int i = 0; i < this->size; ++i) {
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

void Vector::insert_1(int h, int k){

	if (this->capacity > this->size) {
		for (int i = this->size + 1; i > h; --i) {
			this->data[i] = this->data[--i];
		}
		this->data[h] = k;
		this->size++;
		this->data[this->size - 1] = 0;
	}
	else {
		double* data_copy = new double[this->size + 1];
		for (int i = 0; i < h; ++i) {
			data_copy[i] = this->data[i];
		}
		data_copy[h] = k;
		for (int i = h + 1; i < this->size + 1; ++i) {
			data_copy[i] = this->data[i];
		}
		delete[] this->data;
		this->data = data_copy;
		this->capacity++;
		this->size++;
		this->data[this->size - 1] = 0;
	}
}

void Vector::insert_2(int h, int k) {

	resize(this->size + 1);
	for (int i = this->size; i > h; --i) {
		this->data[i] = this->data[i - 1];
	}
	this->data[h] = k;
}

void Vector::erase(int h) {

	for (int i = h; i < this->size; ++i) {
		this->data[i] = this->data[i + 1];
	}
	this->size--;
}

Vector& Vector::operator=(const Vector& v){
	
	if (this == &v) {
		return *this;
	}
	delete[] this->data;
	this->capacity = v.capacity;
	this->size = v.size;
	this->data = new double[this->capacity];
	for (int i = 0; i < this->size; ++i) {
		this->data[i] = v.data[i];
	}
}

std::ostream& operator<<(std::ostream& obj, const Vector& v){

	for (int i = 0; i < v.size; ++i) {
		obj << v.data[i] << " ";
	}
	std::cout << std::endl;
	return obj;
}
