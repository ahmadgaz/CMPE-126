#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle: public Shape {
public:
	Circle(double r) :
			radius(r) {
	}
	double area() const override {
		return 3.14159 * radius * radius;
	}
private:
	double radius;
};

#endif
