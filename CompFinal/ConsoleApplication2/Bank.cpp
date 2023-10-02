#include "Bank.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Bank::Bank() {
	bankName = "N/A";
	bankAddress = "N/A";
	bankHours = "N/A";
	bankAccountVec.push_back(bankAccount);
}

void Bank::startBank() {
	setBankName();
	setBankAddress();
	setBankHours();
	cout << endl;
};

void Bank::runBank() {
	cout << "\nAvailable services for " << getBankName();
		cout << ": Select one of the following numbers to get started: " << endl;
		cout << "1 -- Number of bank accounts" << endl;
		cout << "2 -- Number of saving accounts" << endl;
		cout << "3 -- Number of checking accounts" << endl;
		cout << "4 -- Open bank account" << endl;
		cout << "5 -- Close bank account" << endl;
		cout << "6 -- Modify bank account" << endl;
		cout << "7 -- Detailed bank account information" << endl;
		cout << "8 -- Brief bank accounts info sorted based on aggregate balances" << endl;
		cout << "9 -- Exit" << endl;

		cin >> userInt;
		choice();
};

void Bank::setBankName() {
	cout << "Set bank name: ";
	string temp;
	getline(cin, temp);
	bankName = temp;
};
void Bank::setBankAddress() {
	cout << "Set bank address: ";
	string temp;
	getline(cin, temp);
	bankAddress = temp;
};
void Bank::setBankHours() {
	cout << "Set bank working hours: ";
	string temp;
	getline(cin, temp);
	bankHours = temp;
};
void Bank::choice()
{
	if (userInt > 9 || userInt < 1) {
		cout << "Please choose a different number!\n" << endl;
		runBank();
	}
	else if (userInt == 1) {
		cout << "\nNumber of bank accounts currently: ";
		if (count == 0) {
			cout << "No accounts!\n" << endl;
		}
		else {
			cout << bankAccount->getBankAccountAmount() << "\n" << endl;
		}
		runBank();
	}
	else if (userInt == 2) {
		cout << "\nNumber of saving accounts currently: ";
		cout << getTotalNumOfSavings() << endl;
		runBank();
	}
	else if (userInt == 3) {
		cout << "\nNumber of checking accounts currently: ";
		cout << getTotalNumOfCheckings() << endl;
		runBank();
	}
	else if (userInt == 4) {
		count++;
		bankAccountVec.push_back(createBankAccount(bankAccount));
		bankAccountVec.at(count)->setNumAccs(count);
		bankAccountVec.at(count)->setDetails();
		bankAccountVec.at(count)->runBankAccountMenu();
		runBank();
	}
	else if (userInt == 5) {
		cout << "\nClosing bank account..." << endl;
		closeBankAccount();
		runBank();
	}
	else if (userInt == 6) {
		cout << "\nModifying bank account..." << endl;
		modifyBankAccount();
		runBank();
	}
	else if (userInt == 7) {
		detailedInfo();
		runBank();
	}
	else if (userInt == 8) {
		simpleInfo();
		runBank();
	}
	else if (userInt == 9) {
		cout << "\nThank you. Goodbye." << endl;
	}
};
void Bank::closeBankAccount()
{
	cout << "\nPlease select BankAccount: ";
	if (count == 0) {
		cout << "No accounts!\n" << endl;
	}
	else {
		cout << endl;
		for (int i = 1; i < bankAccountVec.size(); i++) {
			cout << i << " -- " << bankAccountVec.at(i)->getFullPin() << endl;
		}
		cout << endl;
		int userInt;
		cin >> userInt;
		if (userInt < 1 || userInt > bankAccountVec.size()) {
			cout << "\nPlease select a number!" << endl;
			closeBankAccount();
		}
		else {
			cout << "\nClosing Bank Account " << bankAccountVec.at(userInt)->getFullPin() << "!" << endl;
			bankAccountVec.at(userInt) = bankAccountVec.at(bankAccountVec.size() - 1);
			bankAccountVec.pop_back();
			if (userInt != 1 || userInt != bankAccountVec.size()) {
				BankAccount* temp = bankAccountVec.at(userInt);
				bankAccountVec.at(userInt) = bankAccountVec.at(bankAccountVec.size() - 1);
				bankAccountVec.at(bankAccountVec.size() - 1) = temp;
			}
			count--;
			bankAccount->setNumAccs(count);
			cout << "\nClosed!\n" << endl;
		}
	}

};
void Bank::modifyBankAccount()
{
	if (selectBankAccount() == true) {
		cout << endl;
		int userInt;
		cin >> userInt;
		if (userInt < 1 || userInt > bankAccountVec.size()) {
			cout << "\nPlease select a number!" << endl;
			modifyBankAccount();
		}
		else {
			cout << "\nModifiying Bank Account " << bankAccountVec.at(userInt)->getFullPin() << "!" << endl;
			bankAccountVec.at(userInt)->runBankAccountMenu();
		}
	}

};
void Bank::detailedInfo()
{
	printInfo();
	cout << "With total of: $" << getTotalBalance();
	cout << endl;
	for (int i = 1; i < bankAccountVec.size(); i++) {
		cout << "\nFull name of Bank Account holder: " << bankAccountVec.at(i)->getFirstName() << " " << bankAccountVec.at(i)->getLastName() << endl;
		cout << "SSN: "; bankAccountVec.at(i)->getSSN();
		cout << "Amount of sub-accounts: " << bankAccountVec.at(i)->getNumAcc() << "\n" << endl;
		bankAccountVec.at(i)->getDetailData();
	}
};
void Bank::simpleInfo()
{
	cout << endl;
	for (int i = 1; i < bankAccountVec.size(); i++) {
		cout << "Simplified information of " << bankAccountVec.at(i)->getFullPin();
		bankAccountVec.at(i)->getSimpleData();
	}
};
int Bank::getTotalBalance() const
{
	int total = 0;
	for (int i = 1; i < bankAccountVec.size(); i++) {
		total += bankAccountVec.at(i)->getAggregateBal();
	}
	return total;
};
bool Bank::selectBankAccount()
{
	cout << "\nPlease select BankAccount: ";
	if (count == 0) {
		cout << "No accounts!\n" << endl;
		return false;
	}
	else {
		cout << endl;
		for (int i = 1; i < bankAccountVec.size(); i++) {
			cout << i << " -- " << bankAccountVec.at(i)->getFullPin() << endl;
		}
	}
	return true;
};
void Bank::printInfo()
{
	cout << "\nBank's name: " << getBankName() << endl;
	cout << "Bank's address: " << getBankAddress() << endl;
	cout << "Bank's hours: " << getBankHours() << endl;
	cout << "Aggregated balanced of all accounts: " << endl;
	cout << "Holds " << bankAccount->getBankAccountAmount() << " bank accounts." << endl;

	cout << endl;

	if (count == 0) {
		cout << "No bank accounts!\n" << endl;
	}
	else {
		for (int i = 1; i < bankAccountVec.size(); i++) {
			cout << "Bank account pin: " << bankAccountVec.at(i)->getFullPin() << endl;
			cout << "Bank account holder's full name: " << bankAccountVec.at(i)->getFirstName() << " " << bankAccountVec.at(i)->getLastName() << endl;
			cout << "Aggregated balanced of bank account: " << endl;
			cout << "Currently holding " << endl;
		}
	}
};
BankAccount* Bank::createBankAccount(BankAccount*& bankAccount)
{
	this->bankAccount = new BankAccount(getTotalNumOfSavings(), getTotalNumOfCheckings());
	return this->bankAccount;

}
int Bank::getTotalNumOfSavings()
{
	numOfSaving = 0;
	for (int i = 1; i < bankAccountVec.size(); i++) {
		if (bankAccountVec.at(i)->getSavingsNum() > 0) {
			numOfSaving += bankAccountVec.at(i)->getSavingsNum();
		}
		else
		{
			break;
		}
	}
	return numOfSaving;
}
int Bank::getTotalNumOfCheckings()
{
	numOfChecking = 0;
	for (int i = 1; i < bankAccountVec.size(); i++) {
		if (bankAccountVec.at(i)->getCheckingNum() > 0) {
			numOfChecking += bankAccountVec.at(i)->getCheckingNum();
		}
		else
		{
			break;
		}
	}
	return numOfChecking;
};

string Bank::getBankName() const {
	return bankName;
};
string Bank::getBankAddress() const {
	return bankAddress;
};
string Bank::getBankHours() const {
	return bankHours;
};