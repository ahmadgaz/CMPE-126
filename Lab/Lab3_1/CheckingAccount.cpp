#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double initialBalance, double fee) :
		Account(initialBalance), transactionFee(fee) {
}

void CheckingAccount::credit(double amount) {
	Account::credit(amount);
	chargeFee();
}

bool CheckingAccount::debit(double amount) {
	bool success = Account::debit(amount);
	if (success) {
		chargeFee();
	}
	return success;
}

void CheckingAccount::chargeFee() {
	Account::debit(transactionFee);
}
