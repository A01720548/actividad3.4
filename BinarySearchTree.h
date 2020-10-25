#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "TreeNode.h"

#include <iostream>
#include <string>

class BinarySearchTree
{
private:
    TreeNode* root;
    int size;
    void printPreOrderRecursive(TreeNode* which);
    TreeNode* RecursiveInsert(TreeNode* where, string ip, string content);
    TreeNode* RecursiveTop5(TreeNode* where);

public:
    BinarySearchTree(/* args */);
    ~BinarySearchTree();
    void insert(string ip, string content);
    void Inorder(TreeNode* root);
    int getSize();
    void printPreOrder();
    void getTop5Wrapper(TreeNode* root);
};

BinarySearchTree::BinarySearchTree(/* args */)
{
    this->root = nullptr;
    this->size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::insert(string ip, string content)
{
    this->root = RecursiveInsert(root, ip, content);
}

int BinarySearchTree::getSize()
{
    return size;
}


TreeNode* BinarySearchTree::RecursiveInsert(TreeNode* root, string ip, string content)
{
    if (!root) {
        root = new TreeNode(ip, content);
        root->repetitions++;
        this->size++;

    }
    else if (ip > root->ip) {
        root->right = RecursiveInsert(root->right, ip, content);
    }
    else if (ip < root->ip) {
        root->left = RecursiveInsert(root->left, ip, content);
    }
    else
    {
        root->repetitions++;
    }
    return root;
}

TreeNode* BinarySearchTree::RecursiveTop5(TreeNode* where)
{
    int top5[5];

}

void BinarySearchTree::printPreOrder()
{
    printPreOrderRecursive(this->root);
}

void BinarySearchTree::getTop5Wrapper(TreeNode* root)
{
    RecursiveTop5(root);
}

void BinarySearchTree::printPreOrderRecursive(TreeNode* which) {
    if (which != nullptr) {
        std::cout << '[' << which->ip << ' ' << which->content << ' ';
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