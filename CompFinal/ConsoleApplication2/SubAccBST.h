#pragma once
#ifndef SUBACCBST_H
#define SUBACCBST_H
#include "SubAccNode.h"
class SubAccBST {
public:
	SubAccNode* root;
	SubAccBST() { root = nullptr; }
	void insert(SubAccNode* accNode);
	void printSubAccBST_InOrder();
	void remove(int bal);
	SubAccNode* search(int userInt);
	int getHeight();
private:
	SubAccNode* searchRecursive(SubAccNode* accNode, int bal);
	void printSubAccNode_InOrderRecursive(SubAccNode* accNode);
	int getHeightRecursive(SubAccNode* accNode);
};
#endif // !SUBACCBST_H
