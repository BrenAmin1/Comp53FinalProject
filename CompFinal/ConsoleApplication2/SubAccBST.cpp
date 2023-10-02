#include "SubAccBST.h"

void SubAccBST::insert(SubAccNode* accNode)
{
    if (root == nullptr) {
        root = accNode;
    }
    else {
        SubAccNode* currentNode = root;
        while (currentNode != nullptr) {
            if (currentNode->data.getBalance() > accNode->data.getBalance()) {
                if (currentNode->left == nullptr) {
                    currentNode->left = accNode;
                    currentNode = nullptr;
                }   
                else {
                    currentNode = currentNode->left;
                }
            }
            else {
                if (currentNode->right == nullptr) {
                    currentNode->right = accNode;
                    currentNode = nullptr;
                }
                else {
                    currentNode = currentNode->right;
                }
            }
        }
    }
}

void SubAccBST::printSubAccBST_InOrder()
{
    printSubAccNode_InOrderRecursive(root);
}

void SubAccBST::remove(int id)
{
    SubAccNode* par = nullptr;
    SubAccNode* cur = root;
    while (cur != nullptr) {
        if (cur->data.getID() == id) {
            if (cur->left == nullptr && cur->right == nullptr) {
                if (par == nullptr)
                    root = nullptr;
                else if (par->left == cur)
                    par->left = nullptr;
                else
                    par->right = nullptr;

            }
            else if (cur->right == nullptr) {
                if (par == nullptr)
                    root = cur->left;
                else if (par->left == cur)
                    par->left = cur->left;
                else
                    par->right = cur->right;
            }
            else if (cur->left == nullptr) {
                if (par == nullptr)
                    root = cur->right;
                else if (par->left == cur)
                    par->left = cur->right;
                else
                    par->right = cur->right;
            }
            else {
                SubAccNode* suc = cur->right;
                while (suc->left != nullptr) {
                    suc = suc->left;
                    SubAccNode* successorData = suc;
                    cur->data = suc->data;
                }
            }
            return;
        }
        else if (cur->data.getID() < id) {
            par = cur;
            cur = cur->right;
        }
        else {
            par = cur;
            cur = cur->left;
        }
    }
    return;
}

SubAccNode* SubAccBST::search(int userInt)
{
    return searchRecursive(root, userInt);
}

int SubAccBST::getHeight()
{
    return getHeightRecursive(root);
}

SubAccNode* SubAccBST::searchRecursive(SubAccNode* accNode, int id)
{   
    if (accNode != nullptr) {
        if (id == accNode->data.getID())
        {
            return accNode;
        }
        else if (id < accNode->data.getID())
        {
            return searchRecursive(accNode->left, id);
        }
        else
        {
            return searchRecursive(accNode->right, id);
        }
    }
    return nullptr;
}

void SubAccBST::printSubAccNode_InOrderRecursive(SubAccNode* accNode)
{
    if (accNode == nullptr) {
        return;
    }
    printSubAccNode_InOrderRecursive(accNode->right);
    accNode->data.printInfo();
    printSubAccNode_InOrderRecursive(accNode->left);
}

int SubAccBST::getHeightRecursive(SubAccNode* accNode)
{
    if (accNode == nullptr) {
        return -1;
    }
    int leftHeight = getHeightRecursive(accNode->left);
    int rightHeight = getHeightRecursive(accNode->right);
    return 1 + max(leftHeight, rightHeight);
}
