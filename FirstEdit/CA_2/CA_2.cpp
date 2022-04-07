#include <iostream>
#include "Vector.h"

int main() {

	Vector a(5);

	a.insert_2(0, 1);
	a.insert_2(1, 2);
	a.insert_2(2, 3);
	a.print();
	a.insert_1(3, 4);
	a.print();
	a.insert_1(4, 5);
	a.print();
	a.insert_2(5, 6);
	a.print();
	a.erase(0);
	a.print();

	std::cout << a;

	return 0;
}