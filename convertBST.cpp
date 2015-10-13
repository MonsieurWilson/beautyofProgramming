#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(const int v = 0, TreeNode *l = nullptr, TreeNode *r = nullptr): val(v), left(l), right(r) {}
};

void convert(TreeNode *root, TreeNode **lstPtr) {
    if (root == nullptr) {
        return;
    }
    if (root->left) {
        convert(root->left, lstPtr);
    }
    root->left = *lstPtr;
    if (*lstPtr) {
        (*lstPtr)->right = root;
    }
    *lstPtr = root;
    if (root->right) {
        convert(root->right, lstPtr);
    }
}

TreeNode *convert(TreeNode *root) {
    TreeNode *lstPtr = nullptr;
    convert(root, &lstPtr);
    TreeNode *head = lstPtr;
    while (head && head->left) {
        head = head->left;
    }
    return head;
}

int main() {
    return 0;
}
