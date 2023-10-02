#include "SavingAccount.h"
#include <string>
#include <iostream>
using namespace std;

SavingAccount::SavingAccount()
{
	setPin("SAV");
	id = 999;

};
void SavingAccount::setSavingAccDetails()
{
	cout << endl;
	setID(getNumAccs());
	cout << "Set initial balance: ";
	cin >> userInt;
	setInitialBalance(userInt);
	cout << "Current balance is: " << getBalance() << endl;
}
void SavingAccount::setInitialBalance(int balance)
{
	this->balance = balance;
	if (getNumAccs() == 1) {
		cout << "\nFirst savings account receives bonus $100!" << endl;
		this->balance += 100;
	}
};
void SavingAccount::runSavingAccountMenu()
{
	cout << "\nAvailabe services for sub account: " << getFullID() << endl;

	cout << "1 -- Deposit" << endl;
	cout << "2 -- Withdraw" << endl;
	cout << "3 -- Exit" << endl;
	cin >> userInt;
	savingsChoice(userInt);
}
void SavingAccount::savingsChoice(int choice)
{
	if (choice > 3 || choice < 1) {
		cout << "Please choose a different number!\n" << endl;
		runSavingAccountMenu();
	}
	else if (choice == 1) {
		cout << "\nMaking a deposit..." << endl;
		deposit();
		cout << "Depsoit successful! Current balance: " << getBalance() << endl;;
		runSavingAccountMenu();
	}
	else if (choice == 2) {
		cout << "\nMaking a withdrawal..." << endl;
		withdraw();
		cout << "Withdrawal successful! Current balance: " << getBalance() << endl;
		runSavingAccountMenu();
	}
	else if (choice == 3) {
		cout << "\nReturning to previous menu." << endl;
		return;
	}
}
;
