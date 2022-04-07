#pragma once

constexpr auto C = 2;;

class Vector {

private:

	double* data = 0;
	int size = 0;
	int capacity = 0;

public:

	Vector();
	Vector(int n);
	~Vector();
	Vector(const Vector& v);
	Vector& operator=(const Vector& v);

	void resize(int newSize);
	void push_back(int k);
	double pop_back();
	void print();
	void insert_1(int h, int k);
	void insert_2(int h, int k);
	void erase(int h);
	friend std::ostream& operator<<(std::ostream& obj, const Vector& v);

};