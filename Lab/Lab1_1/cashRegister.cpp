#include "cashRegister.h"
#include <iostream>
#include <string>
using namespace std;

string CashRegister::getFormattedPrice(int price) {
	string strPrice = to_string(price);
	if ((int) strPrice.length() == 2) {
		return "$0." + strPrice;
	} else if ((int) strPrice.length() == 1) {
		return "$0.0" + strPrice;
	} else if ((int) strPrice.length() == 0) {
		return "$0.00";
	} else {
		return "$" + strPrice.substr(0, strPrice.length() - 2) + "."
				+ strPrice.substr(strPrice.length() - 2);
	}
}

void CashRegister::deposit(int deposited) {
	amount += deposited;
}
