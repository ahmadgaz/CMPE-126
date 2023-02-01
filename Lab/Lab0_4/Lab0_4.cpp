#include <iostream>
#include <math.h>
using namespace std;

class Triangle {
public:
	Triangle(int x, int y, int z) {
		a = x;
		b = y;
		c = z;
	}
	void getArea() {
		double semi_perimeter = ((a + b + c) / 2);
		double area = sqrt(
				semi_perimeter * (semi_perimeter - a) * (semi_perimeter - b)
						* (semi_perimeter - c));
		cout << "Area: " << area << " units" << endl;
	}
	void getPerimeter() {
		cout << "Perimeter: " << a + b + c << " units" << endl;
	}
private:
	int a;
	int b;
	int c;
};

int main() {
	Triangle triangle1(3, 4, 5);
	triangle1.getArea();
	triangle1.getPerimeter();
	return 0;
}
