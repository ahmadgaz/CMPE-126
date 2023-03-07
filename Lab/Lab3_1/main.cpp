#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount(1000.0, 5.0));
    accounts.push_back(new CheckingAccount(500.0, 0.5));

    for (auto account : accounts) {
        cout << "Processing account with balance: " << account->getBalance() << endl;

        double withdraw, deposit;
        cout << "Enter amount to withdraw: ";
        cin >> withdraw;
        account->debit(withdraw);

        cout << "Enter amount to deposit: ";
        cin >> deposit;
        account->credit(deposit);

        // Determine the account type and perform type-specific actions
        if (SavingsAccount* savings_account = dynamic_cast<SavingsAccount*>(account)) {
            double interest = savings_account->calculateInterest();
            savings_account->credit(interest);
        }
        else if (CheckingAccount* checking_account = dynamic_cast<CheckingAccount*>(account)) {
            checking_account->chargeFee();
        }

        // Print balance
        cout << "Updated balance: " << account->getBalance() << endl;
    }

    for (auto account : accounts) {
        delete account;
    }

    return 0;
}
