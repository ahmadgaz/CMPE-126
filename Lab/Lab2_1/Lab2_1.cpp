#include <iostream>

void switchOperands(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int a = 5;
	int b = 10;
	std::cout << "Before switch: a = " << a << ", b = " << b << std::endl;
	switchOperands(&a, &b);
	std::cout << "After switch: a = " << a << ", b = " << b << std::endl;
	return 0;
}
