#include "101-SymmetricTree.h"

bool SymmetricTree::isTheSame(TreeNode *leftRoot, TreeNode *rightRoot) {
    if (leftRoot == nullptr || rightRoot == nullptr) {
        return (leftRoot == rightRoot);
    }

    if (leftRoot->val != rightRoot->val) {
        return false;
    }

    return isTheSame(leftRoot->left, rightRoot->right) && isTheSame(leftRoot->right, rightRoot->left);
}

bool SymmetricTree::isSymmetric(TreeNode *root) {
    if (root == nullptr) {
        return false;
    }

    return isTheSame(root->left, root->right);
}
