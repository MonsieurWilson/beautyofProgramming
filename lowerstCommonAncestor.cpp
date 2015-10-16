#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode *> children;
    TreeNode(const int v): val(v) {}
};

bool getNodePath(TreeNode *root, TreeNode *node, vector<TreeNode *> &path) {
    if (root == node) {
        return true;
    }
    path.push_back(root);
    bool found = false;
    for (auto itr = root->children.begin(); itr != root->children.end(); ++itr) {
        found = getNodePath(*itr, node, path);
        if (found) {
            return true;
        }
    }
    path.pop_back();
    return false;
}

TreeNode *getPathLastCommonNode(const vector<TreeNode *> &path1, const vector<TreeNode *> &path2) {
    auto itr1 = path1.begin(), itr2 = path2.begin();
    auto ret = path1.begin();
    while (itr1 < path1.end() && itr2 < path2.end() && *itr1 == *itr2) {
        ret = itr1;
    }
    return *ret;
}

TreeNode *getLCA(TreeNode *root, TreeNode *ptr1, TreeNode *ptr2) {
    vector<TreeNode *> path1, path2;
    getNodePath(root, ptr1, path1);
    getNodePath(root, ptr2, path2);
    return getPathLastCommonNode(path1, path2);
}

int main() {
    
    return 0;
}
