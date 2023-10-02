#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "SubAccBST.h"
#include <string>
#include <vector>
using namespace std;

class BankAccount {
public:
	BankAccount();
	BankAccount(int extra, int extra2);
	void runBankAccountMenu();
	void choice(int userInt);
	SavingAccount* createSavingAccount(SavingAccount*& account);
	CheckingAccount* createCheckingAcc(CheckingAccount*& checkingAcc);

	void setFirstName();
	void setLastName();
	void setSSN();
	void setNumAccs(int numOfBankAccs);
	void setDetails();

	string getFirstName() const;
	string getLastName() const;
	void getSSN() const;
	void setID();
	void setExtra(int extra);
	void setExtra2(int extra2);
	
	void modifySubAcc();
	bool selectSubAcc();
	int getSavingsNum() const;
	int getCheckingNum() const;

	void closeSubAcc();
	void getDetailData();
	void getSimpleData();
	int getNumAcc();
	int getAggregateBal();

	int getExtra() const;
	int getExtra2() const;
	int getID() const;
	string getPin() const;
	string getFullPin() const;

	int getBankAccountAmount() const;

private:
	string pin;
	int id;
	int numOfBankAccs;
	int savingAccCount = 0;
	int checkingAccCount = 0;
	int count = 0;

	string firstName;
	string lastName;
	int SSN;
	string userStr = "";
	int userInt = 0;
	SavingAccount* savingAcc;
	vector<SavingAccount*> savingAccVec;
	CheckingAccount* checkingAcc;
	vector<CheckingAccount*> checkingAccVec;
	SubAccBST accBST;
	int extra;
	int extra2;
};
#endif