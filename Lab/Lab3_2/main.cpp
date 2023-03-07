#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main() {
	int size;
	cout << "Enter the number of shapes: ";
	cin >> size;
	vector<Shape*> shapes(size);

	for (int i = 0; i < size; i++) {
		int choice;
		double param1, param2;
		cout << "Enter 1 for Circle, 2 for Rectangle, 3 for Triangle: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter radius: ";
			cin >> param1;
			shapes[i] = new Circle(param1);
			break;
		case 2:
			cout << "Enter width: ";
			cin >> param1;
			cout << "Enter height: ";
			cin >> param2;
			shapes[i] = new Rectangle(param1, param2);
			break;
		case 3:
			cout << "Enter base: ";
			cin >> param1;
			cout << "Enter height: ";
			cin >> param2;
			shapes[i] = new Triangle(param1, param2);
			break;
		default:
			cout << "Invalid choice." << endl;
			i--;
			break;
		}
	}

	for (int i = 0; i < size; i++) {
		cout << "Area of shape " << i + 1 << ": " << shapes[i]->area() << endl;
		delete shapes[i];
	}

	return 0;
}
