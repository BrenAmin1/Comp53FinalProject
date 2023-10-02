#pragma once
#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include <string>
#include "SubAccount.h"
using namespace std;
class SavingAccount : virtual public SubAccount {
public:
	SavingAccount();
	void setSavingAccDetails();
	void setInitialBalance(int balance) override;
	void runSavingAccountMenu();
	void savingsChoice(int choice);
private:
	int userInt = 0;
};
#endif // !SAVINGACCOUNT_H
