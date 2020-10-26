#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "TreeNode.h"

#include <iostream>
#include <string>
#include <vector>

class BinarySearchTree
{
private:
    TreeNode* root;

    int size;
    void printPreOrderRecursive(TreeNode* which);
    TreeNode* RecursiveInsert(TreeNode* where, string ip, string content);
    void RecursiveTop5(TreeNode* where);
    vector<TreeNode*> repetidos;
    void sortRepetidos();


public:
    BinarySearchTree(/* args */);
    ~BinarySearchTree();
    void insert(string ip, string content);
    int getSize();
    void printPreOrder();
    void getTop5();

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

void BinarySearchTree::RecursiveTop5(TreeNode* where)
{
    if (!where) {
        return;
    }
    else
    {
        if (where->repetitions > 1) {
            repetidos.push_back(where);
            cout << "repedito" << endl;
        }

        RecursiveTop5(where->left);
        RecursiveTop5(where->right);


    }


}

void BinarySearchTree::sortRepetidos()
{
    TreeNode* temp;
    for (int i = 0; i < repetidos.size(); i++)
    {
        for (int j = i + 1; j < repetidos.size(); j++)
        {
            if (repetidos[j]->repetitions > repetidos[i]->repetitions) {
                repetidos[i] = temp;
                repetidos[i] = repetidos[j];
                repetidos[j] = temp;

            }
        }

    }

}


void BinarySearchTree::printPreOrder()
{
    printPreOrderRecursive(this->root);
}

void BinarySearchTree::getTop5()
{
    RecursiveTop5(this->root);
    cout << repetidos.size() << endl;
    sortRepetidos();

    for (int i = 0; i < 5; i++)
    {
        cout << repetidos[i]->ip << ' ' << repetidos[i]->content << ' ' << repetidos[i]->repetitions << endl;
    }
    //cout << root->right->repetitions;

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