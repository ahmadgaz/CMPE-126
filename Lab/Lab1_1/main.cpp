#include "cashRegister.h"
#include "dispenserType.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> costs { 125, 150, 225, 150 };
	vector<string> juices { "Apple", "Orange", "Mango Lassi", "Fruit punch" };
	vector<DispenserType> dispensers;
	CashRegister reg;

	// Create dispensers with juices
	for (int i = 0; i < (int) juices.size(); i++) {
		DispenserType dispenser(juices[i], costs[i], 10);
		dispensers.push_back(dispenser);
	}

	while (1) {
		// Pick an Item
		cout << "Welcome to the Juice Dispenser!\n\n";
		cout << "Enter the number of your chosen item:\n";
		for (int i = 0; i < (int) dispensers.size(); i++) {
			cout << i + 1 << ". " << dispensers[i].getName() << "	Remaining: "
					<< dispensers[i].getStock() << endl;
		}

		int choice = 0;
		cin >> choice;

		if (choice - 1 < 0 || choice - 1 > (int)dispensers.size() - 1) {
			cout << "\nInvalid Choice!\n\n";
			continue;
		}

		if (dispensers[choice - 1].getStock() <= 0) {
			cout << "\nOut of stock!\n\n";
			continue;
		}

		// Insert coins
		cout << "\nPlease insert "
				<< reg.getFormattedPrice(dispensers[choice - 1].getPrice())
				<< ". Enter -1 to exit\n\n";

		int deposited = 0;
		while (deposited < dispensers[choice - 1].getPrice()) {
			int increment = 0;
			cin >> increment;
			deposited += increment < 0 ? 0 : increment;

			if (increment == -1) {
				deposited = 0;
				choice = 0;
				break;
			}

			if (deposited >= dispensers[choice - 1].getPrice()) {
				reg.deposit(dispensers[choice - 1].getPrice());
				cout << "Change: "
						<< reg.getFormattedPrice(
								deposited - dispensers[choice - 1].getPrice())
						<< endl;
				dispensers[choice - 1].dispense();
				deposited = 0;
				choice = 0;
				break;
			}

			cout
					<< reg.getFormattedPrice(
							dispensers[choice - 1].getPrice() - deposited)
					<< " remaining. Please insert the full amount\n\n";
		}
	}

	return 0;
}
