#pragma once
#ifndef SUBACCNODE_H
#define SUBACCNODE_H
#include "SavingAccount.h"
#include "CheckingAccount.h"
class SubAccNode {
public:
	SubAccount data;
	SubAccNode* left;
	SubAccNode* right;
	SubAccNode(SubAccount subAccount) {
		data = subAccount;
		left = nullptr;
		right = nullptr;
	}
};
#endif // !BANKACCNODE_H
