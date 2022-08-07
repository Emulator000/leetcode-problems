#ifndef LEETCODE_PROBLEMS_0098_VALIDATEBINARYSEARCHTREE_H
#define LEETCODE_PROBLEMS_0098_VALIDATEBINARYSEARCHTREE_H


#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class ValidateBinarySearchTree {
private:
    static bool validateBST(TreeNode *root, long long int max = LLONG_MAX, long long int min = LLONG_MIN);

public:
    static bool isValidBST(TreeNode *root);
    static bool isValidBSTIterative(TreeNode *root);
};


#endif //LEETCODE_PROBLEMS_0098_VALIDATEBINARYSEARCHTREE_H
