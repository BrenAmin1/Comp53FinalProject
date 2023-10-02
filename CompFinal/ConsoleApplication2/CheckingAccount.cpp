#include "CheckingAccount.h"
#include <string>
#include <iostream>
using namespace std;
CheckingAccount::CheckingAccount()
{
	setPin("CHK");
	id = 5999;
	locked = false;
	maxCap = 0;
}

void CheckingAccount::setCheckingDetails()
{
	cout << endl;
	setID(getNumAccs());
	cout << "Set maximum capacity: ";
	cin >> userInt;
	setMaxCap(userInt);
	cout << "Set initial balance: ";
	cin >> userInt;
	setInitialBalance(userInt);
	cout << "Select 1 to lock this account; else any other number suffices to keep account unlocked: ";
	cin >> userInt;
	if (userInt == 1) {
		locked = true;
	}
	cout << "Current balance is: " << getBalance() << endl;
}

void CheckingAccount::runCheckingMenu()
{
	cout << "\nAvailabe services for bank account: " << getFullID() << endl;

	cout << "1 -- Deposit" << endl;
	cout << "2 -- Withdraw" << endl;
	cout << "3 -- Set Max Capacity" << endl;
	cout << "4 -- Lock/Unlock Sub-Account" << endl;
	cout << "5 -- Exit" << endl;
	cin >> userInt;
	checkingChoice(userInt);
}

void CheckingAccount::checkingChoice(int choice)
{
	if (choice > 5 || choice < 1) {
		cout << "Please choose a different number!\n" << endl;
		runCheckingMenu();
	}
	else if (choice == 1) {
		cout << "\nMaking a deposit..." << endl;
		deposit();
		runCheckingMenu();
	}
	else if (choice == 2) {
		cout << "\nMaking a withdrawal..." << endl;
		withdraw();
		
		runCheckingMenu();
	}
	else if (choice == 3) {
		cout << "\nSetting max capacity..." << endl;
		cout << "Set a max capacity: $";
		cin >> userInt;
		setMaxCap(userInt);
		cout << "\nMax cap successfully changed! Current max cap: $" << getMaxCap() << endl;
		runCheckingMenu();
	}
	else if (choice == 4) {
		cout << "\nSetting lock status..." << endl;
		setLock();
		runCheckingMenu();
	}
	else if (choice == 5) {
		cout << "\nReturning to previous menu." << endl;
		return;
	}
}

void CheckingAccount::deposit()
{
	if (isLocked() == true) {
		cout << "Account locked! Unlock to make a deposit" << endl;
	}
	else {
		cout << "Enter deposit amount: ";
		cin >> userInt;
		if ((balance + userInt) > getMaxCap()) {
			cout << "You cannot input more than the maximum capacity!" << endl;
		}
		else {
			balance += userInt;
			cout << "Depsoit successful! Current balance: " << getBalance() << endl;
		}
	}
}

void CheckingAccount::withdraw()
{
	if(isLocked() == true) {
		cout << "Account locked! Unlock to make a deposit" << endl;
	}
	else {
		cout << "Enter withdrawal amount: ";
		cin >> userInt;
		if (getBalance() == 0) {
			cout << "Current balance is $0! Please deposit before trying to withdraw!" << endl;
		}
		else if (1 > userInt) {
			cout << "Please input a number greater than 0!" << endl;
			this->withdraw();
		}
		else if (userInt >= getBalance()) {
			cout << "Overdrawing! Please input a different amount!" << endl;
			this->withdraw();
		}
		else {
			this->balance -= userInt;
			cout << "Withdrawal successful! Current balance: " << getBalance() << endl;
		}
	}
}

void CheckingAccount::setInitialBalance(int balance)
{
	if (balance > getMaxCap()) {
		cout << "You cannot input amount over the cap! Try again." << endl;
		cin >> userInt;
		setInitialBalance(userInt);
	}
	else {
		this->balance = balance;
	}
}


bool CheckingAccount::isLocked()
{
	if (locked == true) {
		return true;
	}
	return false;
}

int CheckingAccount::getMaxCap()
{
	return maxCap;
}

void CheckingAccount::setMaxCap(int max)
{
	maxCap = max;
}

void CheckingAccount::setLock()
{
	if (isLocked() == true) {
		cout << "\nCurrently locked! Setting to unlocked." << endl;
		locked = false;
	}
	else {
		cout << "\nCurrently unlocked! Setting to locked." << endl;
		locked = true;
	}
}
