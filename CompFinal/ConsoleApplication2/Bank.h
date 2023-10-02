#pragma once
#ifndef BANK_H
#define BANK_H
#include <string>
#include <vector>
#include "BankAccount.h"
using namespace std;

//const int maxTableSize = 100;
class Bank {
public:
	Bank();
	void startBank();
	void runBank();
	void setBankName();
	void setBankAddress();
	void setBankHours();
	void choice();
	void closeBankAccount();
	void modifyBankAccount();
	void detailedInfo();
	void simpleInfo();
	int getTotalBalance() const;
	bool selectBankAccount();
	void printInfo();
	BankAccount* createBankAccount(BankAccount *&bankAccount);

	int getTotalNumOfSavings();
	int getTotalNumOfCheckings();
	string getBankName() const;
	string getBankAddress() const;
	string getBankHours() const;
private:
	string bankName;
	string bankAddress;
	string bankHours;

	int count = 0;
	int numOfSaving = 0;
	int numOfChecking = 0;

	string userStr = "";
	int userInt = -1;
	BankAccount* bankAccount;
	vector<BankAccount*> bankAccountVec;
	//BankAccount bankAccountArr[100];
};
#endif