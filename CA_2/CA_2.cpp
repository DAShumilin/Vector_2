#include <iostream>
#include "Vector.h"

int main() {

	Vector a(10);
	a.resize(25);
	a.resize(5);

	Vector b(a);

	a.print();

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);

	a.pop_back();
	a.pop_back();

	a.print();

	a.insert(0, 5);
	a.insert(1, 4);
	a.insert(2, 3);
	a.insert(3, 2);
	a.insert(4, 1);
	a.insert(9, 7);
	a.insert(10, 10);

	a.print();

	a.erase(10);
	a.erase(8);

	a.print();

	Vector c;

	c = a;

	c.print();

	return 0;
}