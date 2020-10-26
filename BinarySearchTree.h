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
    BinarySearchTree();
    void insert(string ip, string content);
    int getSize();
    void printPreOrder();
    void getTop5();

};

/**
 * @brief Construct a new Binary Search Tree:: Binary Search Tree object
 * Complexity: O(1)
 */
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->size = 0;
}


/**
 * @brief Insertion wrapper function
 * Complexity : O(1)
 * @param ip the ip that will be added to the tree
 * @param content What happened in the event
 */
void BinarySearchTree::insert(string ip, string content)
{
    this->root = RecursiveInsert(root, ip, content);
}

/**
 * @brief Returns the size of the tree
 * Complexity: O(1)
 * @return int size
 */
int BinarySearchTree::getSize()
{
    return size;
}

/**
 * @brief Inserts element into BST if it isn't already
 *Complexity: O(logn)
 * @param root Current tree, starting from the root
 * @param ip IP that will be added into list
 * @param content content that will be added into list
 * @return TreeNode* The tree but with the added node
 */
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

/**
 * @brief Function that will find all cases of duplicates and will add them to the vector
 * Complexity: O(n)
 * @param where Root of tree
 */
void BinarySearchTree::RecursiveTop5(TreeNode* where)
{
    if (!where) {
        return;
    }
    else
    {
        if (where->repetitions > 1) {
            repetidos.push_back(where);
        }

        RecursiveTop5(where->left);
        RecursiveTop5(where->right);


    }


}
/**
 * @brief Bubble sort to get the Nodes with the most repetitions
 * Complexity: O(n^2)
 */
void BinarySearchTree::sortRepetidos()
{
    for (int i = 0;i < repetidos.size() - 1;i++)
    {
        for (int j = 0;j < repetidos.size() - i - 1;j++)
        {
            if (repetidos[j]->repetitions < repetidos[j + 1]->repetitions)
            {
                TreeNode* temp = repetidos[j];
                repetidos[j] = repetidos[j + 1];
                repetidos[j + 1] = temp;
            }
        }
    }


}

/**
 * @brief Wrapper function to print tree
 * Complexity: O(1)
 */
void BinarySearchTree::printPreOrder()
{
    printPreOrderRecursive(this->root);
}

/**
 * @brief Wrapper function to print the top 5 most accessed IPs
 * Complexity: O(n)
 */
void BinarySearchTree::getTop5()
{
    RecursiveTop5(this->root);
    cout << repetidos.size() << endl;
    sortRepetidos();
    cout << repetidos.size() << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Numero de Repeticiones: " << repetidos[i]->repetitions << " IP: " << repetidos[i]->ip << " Contenido: " << repetidos[i]->content << endl;
    }

}

/**
 * @brief Function to print Tree
 * Complexity: O(n)
 * @param which
 */
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