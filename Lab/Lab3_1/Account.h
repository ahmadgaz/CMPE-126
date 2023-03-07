#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
	Account();
	Account(double); // constructor initializes balance
	void credit(double); // add an amount to the account balance
	bool debit(double); // subtract an amount from the account balance
	void setBalance(double); // sets the account balance
	double getBalance() const; // return the account balance
	virtual ~Account() = default;
protected:
	double balance; // data member that stores the balance
};

#endif
