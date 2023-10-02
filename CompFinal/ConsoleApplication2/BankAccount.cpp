#include "BankAccount.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

BankAccount::BankAccount() {
	pin = "BNK";
	firstName = "N/A";
	lastName = "N/A";
	numOfBankAccs = 0;
	id = 9999;
	SSN = 000000000;
	extra = 0;
	extra2 = 0;
	savingAccVec.push_back(savingAcc);
	checkingAccVec.push_back(checkingAcc);
}
BankAccount::BankAccount(int extra, int extra2)
{
	pin = "BNK";
	firstName = "N/A";
	lastName = "N/A";
	numOfBankAccs = 0;
	id = 9999;
	SSN = 000000000;
	this->extra = extra;
	this->extra2 = extra2;
	savingAccVec.push_back(savingAcc);
	checkingAccVec.push_back(checkingAcc);
};

void BankAccount::setDetails() {
	cout << endl;
	this->setFirstName();
	this->setLastName();
	this->setSSN();
	this->setID();
	this->setExtra(extra);
	this->setExtra2(extra2);
	cout << endl;

	cout << "Full name: " << getFirstName() << " " << getLastName() << endl;
	cout << "SSN: ";
	getSSN();
	cout << endl;
	cout << "A new Bank Account has successfully been created." << endl;
};

void BankAccount::runBankAccountMenu() {
	cout << "\nAvailabe services for bank account: " << getFullPin() << endl;
	cout << "1 -- Open Saving sub-account" << endl;
	cout << "2 -- Open Checking sub-account" << endl;
	cout << "3 -- Modify a sub-account" << endl;
	cout << "4 -- Close a sub-account" << endl;
	cout << "5 -- Detailed bank account info sorted based on balances of sub-accounts" << endl;
	cout << "6 -- Simple bank account info" << endl;
	cout << "7 -- Exit" << endl;

	cin >> userInt;
	choice(userInt);
}
void BankAccount::choice(int userInt)
{
	if (userInt > 7 || userInt < 1) {
		cout << "Please choose a different number!\n" << endl;
		runBankAccountMenu();
	}
	else if (userInt == 1) {
		savingAccCount++;
		count++;
		savingAccVec.push_back(createSavingAccount(savingAcc));
		savingAccVec.at(savingAccCount)->setNumAccs(savingAccCount);
		savingAccVec.at(savingAccCount)->setExtra(this->getExtra());
		savingAccVec.at(savingAccCount)->setSavingAccDetails();
		savingAccVec.at(savingAccCount)->runSavingAccountMenu();
		SubAccount* s = new SubAccount;
		s->setInitialBalance(savingAccVec.at(savingAccCount)->getBalance());
		s->setPin("SAV");
		s->setNumAccs(savingAccCount);
		s->setID(savingAccCount);
		s->setExtra(this->getExtra());
		SubAccNode* node = new SubAccNode(*s);
		accBST.insert(node);
		runBankAccountMenu();
	}
	else if (userInt == 2) {
		checkingAccCount++;
		count++;
		checkingAccVec.push_back(createCheckingAcc(checkingAcc));
		checkingAccVec.at(checkingAccCount)->setNumAccs(checkingAccCount);
		checkingAccVec.at(checkingAccCount)->setExtra(getExtra2());
		checkingAccVec.at(checkingAccCount)->setCheckingDetails();
		checkingAccVec.at(checkingAccCount)->runCheckingMenu();
		SubAccount* c = new SubAccount;
		c->setInitialBalance(checkingAccVec.at(checkingAccCount)->getBalance());
		c->setPin("CHK");
		int temp = 5000 + checkingAccCount + getExtra2();
		c->setNumAccs(temp);
		c->setExtra(getExtra2());
		c->setID(checkingAccCount);
		SubAccNode* node = new SubAccNode(*c);
		accBST.insert(node);
		runBankAccountMenu();
	}
	else if (userInt == 3) {
		modifySubAcc();
		runBankAccountMenu();
	}
	else if (userInt == 4) {
		cout << "Closing..." << endl;
		closeSubAcc();
		runBankAccountMenu();
	}
	else if (userInt == 5) {
		cout << "\nRetrieving data..." << endl;
		getDetailData();
		runBankAccountMenu();
	}
	else if (userInt == 6) {
		cout << "\nRetrieving data..." << endl;
		getSimpleData();
		runBankAccountMenu();
	}
	else if (userInt == 7) {
		cout << "\nReturning to previous menu." << endl;
	}
};

void BankAccount::setFirstName() {
	cout << "Enter first name of Bank Account holder: ";
	cin >> userStr;
	firstName = userStr;
};
void BankAccount::setLastName() {
	cout << "Enter last name of Bank Account holder: ";
	cin >> userStr;
	lastName = userStr;
};
void BankAccount::setSSN() {
	cout << "Enter SSN (digits only): ";
	int long temp = 0;
	cin >> temp;
	if (temp > 89999999 && temp < 1000000000) {
		SSN = temp;
	}
	else {
		cout << "Enter a legitimate SSN." << endl;
		setSSN();
	}
};
SavingAccount* BankAccount::createSavingAccount(SavingAccount*& savingAcc)
{
	this->savingAcc = new SavingAccount;
	return this->savingAcc;
}
CheckingAccount* BankAccount::createCheckingAcc(CheckingAccount*& checkingAcc)
{
	this->checkingAcc = new CheckingAccount;
	return this->checkingAcc;
}
string BankAccount::getFirstName() const {
	return this->firstName;
};
string BankAccount::getLastName() const {
	return this->lastName;
};
void BankAccount::getSSN() const {
	int temp = SSN;
	cout << (temp / 1000000) << "-";
	temp /= 10000;
	cout << temp % 100 << "-";
	cout << SSN % 10000 << endl;
};

void BankAccount::setID()
{
	this->id += getBankAccountAmount();
}
void BankAccount::setExtra(int extra)
{
	this->extra += extra;
}
void BankAccount::setExtra2(int extra2)
{
	this->extra2 += extra2;
}
void BankAccount::modifySubAcc()
{
	if (selectSubAcc() == true) {
		cout << "\n\nPlease type in unique PIN letters: ";
		string myString;
		cin >> myString;
		userStr = myString;
		cout << "Please type in unique ID numbers: ";
		cin >> userInt;
		cout << "Searching for " << userStr << userInt;
		if (accBST.search(userInt) != nullptr) {
			cout << "... Found!" << endl;
			if (userStr == "SAV") {
				int f = 0;
				for (int i = 1; i < savingAccVec.size(); i++) {
					if (savingAccVec.at(i)->getID() == userInt) {
						f = i;
					}
				}
				savingAccVec.at(f)->runSavingAccountMenu();
			}
			else if (userStr == "CHK") {
				int f = 0;
				for (int i = 1; i < checkingAccVec.size(); i++) {
					if (checkingAccVec.at(i)->getID() == userInt) {
						f = i;
					}
				}
				checkingAccVec.at(f)->runCheckingMenu();
			}
		}
		else { cout << "... Not found!" << endl; }
	}
}
bool BankAccount::selectSubAcc()
{
	cout << "\nPlease select Sub account: ";
	if (count == -1) {
		cout << "No accounts!\n" << endl;
		return false;
	}
	return true;
};
int BankAccount::getSavingsNum() const
{
	return savingAcc->getNumAccs();
}
int BankAccount::getCheckingNum() const
{
	return checkingAcc->getNumAccs();
}
;
void BankAccount::closeSubAcc()
{
	if (selectSubAcc() == true) {
		cout << "\n\nPlease type in unique PIN letters: ";
		cin >> userStr;
		cout << "Please type in unique ID numbers: ";
		cin >> userInt;
		cout << "Searching for " << userStr << userInt;
		if (accBST.search(userInt) != nullptr) {
			cout << "... Found!" << endl;
			if (userStr == "SAV") {
				int f = 0;
				for (int i = 1; i < savingAccVec.size(); i++) {
					if (savingAccVec.at(i)->getID() == userInt) {
						f = i;
						break;
					}
				}
				accBST.remove(savingAccVec.at(f)->getID());
				savingAccVec.at(f) = savingAccVec.at(savingAccVec.size() - 1);
				savingAccVec.pop_back();
				if (f != 1 || f != savingAccVec.size()) {
					SavingAccount* temp = savingAccVec.at(f);
					savingAccVec.at(f) = savingAccVec.at(savingAccVec.size() - 1);
					savingAccVec.at(savingAccVec.size() - 1) = temp;
				}
				savingAccCount--;
				savingAcc->setNumAccs(savingAccCount);
				cout << "\nClosed!\n" << endl;
			}
			else if (userStr == "CHK") {
				int f = 0;
				for (int i = 1; i < checkingAccVec.size(); i++) {
					if (checkingAccVec.at(i)->getID() == userInt) {
						f = i;
						break;
					}
				}
				accBST.remove(checkingAccVec.at(f)->getID());
				checkingAccVec.at(f) = checkingAccVec.at(checkingAccVec.size() - 1);
				checkingAccVec.pop_back();
				if (f != 1 || f != checkingAccVec.size()) {
					CheckingAccount* temp = checkingAccVec.at(f);
					checkingAccVec.at(f) = checkingAccVec.at(checkingAccVec.size() - 1);
					checkingAccVec.at(checkingAccVec.size() - 1) = temp;
				}
				checkingAccCount--;
				checkingAcc->setNumAccs(checkingAccCount);
				cout << "\nClosed!\n" << endl;
			}
		}
		else { cout << "... Not found!" << endl; }
	}
}
void BankAccount::getDetailData()
{
	accBST.printSubAccBST_InOrder();
}
void BankAccount::getSimpleData()
{
	cout << "\nNum of sub-accounts: " << getNumAcc() << " with aggregated balance of: " << getAggregateBal() << endl;
}
int BankAccount::getNumAcc()
{
	return count;
}
int BankAccount::getAggregateBal()
{
	int total = 0;
	for (int i = 1; i < savingAccVec.size(); i++) {
		total += savingAccVec.at(i)->getBalance();
	}
	for (int i = 1; i <  checkingAccVec.size(); i++) {
		total += checkingAccVec.at(i)->getBalance();
	}
	return total;
}
int BankAccount::getExtra() const
{
	return extra;
}
int BankAccount::getExtra2() const
{
	return extra2;
}
;

void BankAccount::setNumAccs(int numOfBankAccs)
{
	this->numOfBankAccs = numOfBankAccs;
};

int BankAccount::getID() const {
	return this->id;
};

string BankAccount::getPin() const {
	return this->pin;
};
string BankAccount::getFullPin() const {
	return this->getPin() + to_string(this->getID());
};

int BankAccount::getBankAccountAmount() const {
	return numOfBankAccs;
}
