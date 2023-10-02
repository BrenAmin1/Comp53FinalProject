#include "SubAccount.h"
#include <iostream>
#include <string>

SubAccount::SubAccount() {
	this->pin = "TMP";
	this->balance = 0;
	this->id = 999;
	this->numOfAccs = 0;
	this->extra = 0;
}
void SubAccount::deposit()
{
	cout << "Enter deposit amount: ";
	cin >> userInt;
	if (0 > userInt) {
		cout << "Please input a number greater than 0!" << endl;
		this->deposit();
	}
	else {
		this->balance += userInt;
	}
	
}

void SubAccount::withdraw()
{
	cout << "Enter withdrawal amount: ";
	cin >> userInt;
	if (getBalance() == 0) {
		cout << "Current balance is $0! Please deposit before trying to withdraw!" << endl;
	}
	else if (1 > userInt) {
		cout << "Please input a number greater than 0!" << endl;
		this->withdraw();
	}
	else if(userInt >= getBalance()) {
		cout << "Overdrawing! Please input a different amount!" << endl;
		this->withdraw();
	}
	else {
		this->balance -= userInt;
	}
}

int SubAccount::getBalance()
{
	return this->balance;
}

string SubAccount::getFullID()
{
	return getPin() + to_string(getID());
}

void SubAccount::printInfo()
{
	cout << "Sub Account Unique ID: " << getFullID() << endl;
	cout << "Balance: " << getBalance() << endl;
}

void SubAccount::setPin(string pin)
{
	this->pin = pin;
}

void SubAccount::setID(int id)
{
	this->id = getID() + getNumAccs() + getExtra();
}

void SubAccount::setNumAccs(int accs)
{
	this->numOfAccs += accs;
}

void SubAccount::setInitialBalance(int balance)
{
	this->balance = balance;
}

void SubAccount::setExtra(int extra)
{
	this->extra += extra;
}

int SubAccount::getExtra()
{
	return this->extra;
}

int SubAccount::getID()
{
	return this->id;
}

string SubAccount::getPin()
{
	return this->pin;
}

int SubAccount::getNumAccs()
{
	return this->numOfAccs;
}

