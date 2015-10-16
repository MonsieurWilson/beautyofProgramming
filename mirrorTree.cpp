#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode (const int v = 0, TreeNode *l = nullptr, TreeNode *r = nullptr): val(v), left(l), right(r) {}
};

TreeNode *mirrorTree(TreeNode *root) {
    if (!root) {
        return nullptr;
    }
    TreeNode *mirror = new TreeNode(root->val);
    if (root->left) {
        mirror->right = mirrorTree(root->left);
    }
    if (root->right) {
        mirror->left = mirrorTree(root->right);
    }
    return mirror;
}
