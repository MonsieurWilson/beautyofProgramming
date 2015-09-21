#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    int val;
    int leftMax, rightMax;
    TreeNode(const int &v): val(v), left(nullptr), right(nullptr), leftMax(0), rightMax(0) {}
};

void maxDist(TreeNode *root, int &dist) {
    if (!root) {
        return;
    }
    if (!root->left) {
        root->leftMax = 0;
    }
    else {
        maxDist(root->left, dist);
    }
    if (!root->right) {
        root->rightMax = 0;
    }
    else {
        maxDist(root->right, dist);
    }
    if (root->left) {
        root->leftMax = max(root->left->leftMax, root->left->rightMax) + 1;
    }
    if (root->right) {
        root->rightMax = max(root->right->leftMax, root->right->rightMax) + 1;
    }
    dist = max(dist, root->leftMax + root->rightMax);
}

class Tree{
public:
    static TreeNode *crtTree(const vector<string> &vec){
        queue<TreeNode *> q;
        TreeNode *root = nullptr;
        if (vec.size() > 0){
            root = new TreeNode(atoi(vec[0].c_str()));
            q.push(root);
        }
        int idx = 1;
        while (idx < vec.size()){
            if (q.front() == nullptr){
                q.pop();
                continue;
            }
            if (vec[idx] != string("#")){
                q.front()->left = new TreeNode(atoi(vec[idx].c_str()));
            }
            if (idx != vec.size() - 1 && vec[idx + 1] != string("#")){
                q.front()->right = new TreeNode(atoi(vec[idx + 1].c_str()));
            }
            q.push(q.front()->left);
            q.push(q.front()->right);
            q.pop();
            idx += 2;
        }
        return root;
    }
};

int main() {
    cout << "Input the size of the vector:" << endl;
    int lens;
    cin >> lens;
    vector<string> vec(lens);
    cout << "Input the vector's elements:" << endl;
    for (int i = 0; i < lens; ++i) {
        cin >> vec[i];
    }

    TreeNode *root = Tree::crtTree(vec);
    int dist = 0;
    maxDist(root, dist);
    cout << "The max distance of the binary tree is: " << dist << endl;

    return 0;
}
