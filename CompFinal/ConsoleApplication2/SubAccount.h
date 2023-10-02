#pragma once
#ifndef SUBACCOUNT_H
#define SUBACCOUNT_H
#include <string>
using namespace std;

class SubAccount {
public:
	SubAccount();
	virtual void deposit();
	virtual void withdraw();
	

	virtual void setPin(string pin);
	virtual void setID(int id);
	virtual void setNumAccs(int accs);
	virtual void setInitialBalance(int balance);
	virtual void setExtra(int extra);
	virtual int getExtra();

	virtual int getID();
	virtual string getPin();
	virtual int getNumAccs();
	virtual int getBalance();
	virtual string getFullID();
	virtual void printInfo();

protected:
	int balance;
	string pin; 
	int id;
	int numOfAccs;
	int userInt;
	int extra;
};
#endif // !ACCOUNT_H
