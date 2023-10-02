#pragma once
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "SubAccount.h"
using namespace std;
class CheckingAccount : virtual public SubAccount {
public:
	CheckingAccount();
	void setCheckingDetails();
	void runCheckingMenu();
	void checkingChoice(int choice);
	void deposit() override;
	void withdraw() override;
	void setInitialBalance(int balance) override;

	bool isLocked();
	int getMaxCap();
	void setMaxCap(int max);
	void setLock();
private:
	bool locked;
	int maxCap;
};
#endif // !CHECKINGACCOUNT_H
