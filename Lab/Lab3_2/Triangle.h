#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle: public Shape {
public:
	Triangle(double b, double h) :
			base(b), height(h) {
	}
	double area() const override {
		return 0.5 * base * height;
	}
private:
	double base;
	double height;
};

#endif
