#include <iostream>
using namespace std;

class BasicShape {
protected:
	double area;
public:
	virtual void calcArea() = 0;
	double getArea() {
		return area;
	}
	virtual ~BasicShape() {
	}
};

class Circle: public BasicShape {
private:
	int centerX_;
	int centerY_;
	int radius_;
public:
	Circle(int centerX, int centerY, int radius) :
			centerX_(centerX), centerY_(centerY), radius_(radius) {
	}
	;
	int getCenterX() {
		return centerX_;
	}
	int getCenterY() {
		return centerY_;
	}
	void calcArea() override {
		area = 3.14 * radius_ * radius_;
		return;
	}
};

class Rectangle: public BasicShape {
private:
	int length_;
	int width_;
public:
	Rectangle(int length, int width) :
			length_(length), width_(width) {
	}
	;
	int getLength() {
		return length_;
	}
	int getWidth() {
		return width_;
	}
	void calcArea() override {
		area = length_ * width_;
		return;
	}
};

int main() {
	BasicShape *shape2 = new Circle(1, 2, 3);
	BasicShape *shape1 = new Rectangle(5, 4);

	shape2->calcArea();
	shape1->calcArea();

	cout << "Circle Area: " << shape2->getArea() << endl;
	cout << "Rectangle Area: " << shape1->getArea() << endl;

	return 0;
}
