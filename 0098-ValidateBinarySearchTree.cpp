#include "0098-ValidateBinarySearchTree.h"

#include <stack>

using namespace std;

bool ValidateBinarySearchTree::validateBST(TreeNode *root, long long int max, long long int min) {
    if (root == nullptr) {
        return true;
    }

    if (root->val >= max || root->val <= min) {
        return false;
    }

    return validateBST(root->left, root->val, min) && validateBST(root->right, max, root->val);
}

bool ValidateBinarySearchTree::isValidBST(TreeNode *root) {
    return validateBST(root);
}

bool ValidateBinarySearchTree::isValidBSTIterative(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    stack<TreeNode *> st;
    TreeNode *cursor = root, *previous = nullptr;

    while (cursor != nullptr || !st.empty()) {
        if (cursor != nullptr) {
            st.push(cursor);
            cursor = cursor->left;

            continue;
        }

        cursor = st.top();
        st.pop();

        if (previous != nullptr && cursor->val <= previous->val) {
            return false;
        }

        previous = cursor;
        cursor = cursor->right;
    }

    return true;
}
