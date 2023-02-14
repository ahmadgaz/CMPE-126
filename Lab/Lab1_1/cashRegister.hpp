#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include <iostream>
#include <string>
using namespace std;

class CashRegister {
private:
	long amount;
public:
	CashRegister() :
			amount(0) {
	}
	CashRegister(long amount) :
			amount(amount) {
	}
	string getFormattedPrice(int price);
	void deposit(int deposited);
};

#endif /* CASHREGISTER_H */
