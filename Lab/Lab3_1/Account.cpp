#include "Account.h"

Account::Account() :
		balance(0.0) {
}

Account::Account(double initialBalance) :
		balance(initialBalance) {
}

void Account::credit(double amount) {
	balance += amount;
}

bool Account::debit(double amount) {
	if (amount > balance) {
		return false; // insufficient funds
	} else {
		balance -= amount;
		return true;
	}
}

void Account::setBalance(double newBalance) {
	balance = newBalance;
}

double Account::getBalance() const {
	return balance;
}
