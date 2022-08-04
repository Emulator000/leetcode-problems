#ifndef LEETCODE_PROBLEMS_SYMMETRICTREE_H
#define LEETCODE_PROBLEMS_SYMMETRICTREE_H


struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
};

class SymmetricTree {
private:
    static bool isTheSame(TreeNode *leftRoot, TreeNode *rightRoot);

public:
    static bool isSymmetric(TreeNode *root);
};


#endif //LEETCODE_PROBLEMS_SYMMETRICTREE_H
