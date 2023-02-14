#include "dispenserType.h"
#include <iostream>
#include <string>
using namespace std;

void DispenserType::dispense() {
	stock -= 1;
	cout << "Enjoy your " << name << " Juice!\n\n";
}
