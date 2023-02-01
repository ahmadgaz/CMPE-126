#include <iostream>
using namespace std;

class Rectangle {
public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}
	void getArea(){
		cout << "Area: " << length*breadth << " units" <<  endl;
	}
private:
	int length;
	int breadth;
};

int main() {
	Rectangle rectangle1(4, 5);
	Rectangle rectangle2(5, 8);
	rectangle1.getArea();
	rectangle2.getArea();
	return 0;
}
