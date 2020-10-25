#ifndef __TreeNode_H__
#define __TreeNode_H__

#include <string>
#include <iostream>

using namespace std;

class TreeNode
{
public:
    string ip;
    string content;
    int repetitions;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string, string, int);

};

/**
 * @brief Construct a new node with a parameter
 *
 * @param datum Data that will go into tree
 */
TreeNode::TreeNode(string ip, string content, int repetitions)
{
    this->ip = ip;
    this->content = content;
    this->repetitions = repetitions;
    this->right = this->left = nullptr;
}



#endif // __TreeNode_H__