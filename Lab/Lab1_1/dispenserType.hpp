#ifndef DISPENSERTYPE_H
#define DISPENSERTYPE_H
#include <iostream>
#include <string>
using namespace std;

class DispenserType {
private:
	string name;
	int price;
	int stock;
public:
	DispenserType() :
			name("null"), price(0), stock(0) {
	}
	DispenserType(string name, int price, int stock) :
			name(name), price(price), stock(stock) {
	}
	string getName() {
		return name;
	}
	int getPrice() {
		return price;
	}
	int getStock() {
		return stock;
	}
	void dispense();
};

#endif /* DISPENSERTYPE_H */
