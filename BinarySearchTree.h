#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "TreeNode.h"

#include <iostream>
class BinarySearchTree
{
private:
    TreeNode* root;
    int size;
    void printPreOrderRecursive(TreeNode* which);
    TreeNode* RecursiveInsert(TreeNode* where, int datum);

public:
    BinarySearchTree(/* args */);
    ~BinarySearchTree();
    void insert(int datum);
    void Inorder(TreeNode* root);
    int getSize();
    void printPreOrder();
};

BinarySearchTree::BinarySearchTree(/* args */)
{
    this->root = nullptr;
    this->size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(int datum)
{
    this->root = RecursiveInsert(root, datum);
}

int BinarySearchTree::getSize()
{
    return size;
}


TreeNode* BinarySearchTree::RecursiveInsert(TreeNode* root, int datum)
{
    if (!root) {
        root = new TreeNode(datum);
        this->size++;

    }
    else if (datum > root->datum) {
        root->right = RecursiveInsert(root->right, datum);
    }
    else if (datum < root->datum) {
        root->left = RecursiveInsert(root->left, datum);
    }
    else
    {
        std::cout << "Element already exists";
    }
    return root;
}

void BinarySearchTree::printPreOrder()
{
    printPreOrderRecursive(this->root);
}

void BinarySearchTree::printPreOrderRecursive(TreeNode* which) {
    if (which != nullptr) {
        std::cout << '[' << which->datum << ' ';
        printPreOrderRecursive(which->left);
        printPreOrderRecursive(which->right);
        std::cout << ']';

    }
    else
    {
        std::cout << "[]";
    }

}

#endif // __BINARYSEARCHTREE_H__