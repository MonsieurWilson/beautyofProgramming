#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int v): left(nullptr), right(nullptr), val(v) {}
};

TreeNode *build(vector<int>::iterator preBeg, vector<int>::iterator preEnd, vector<int>::iterator inBeg, vector<int>::iterator inEnd) {
    if (preBeg == preEnd || inBeg == inEnd) {
        return nullptr;
    }
    int lens = preEnd - preBeg;
    TreeNode *root = new TreeNode(*preBeg);
    if (lens == 1) {
        return root;
    }
    vector<int>::iterator pos = inBeg;
    while (pos != inEnd) {
        if (*pos = *preBeg) {
            break;
        }
        ++pos;
    }
    int leftLens = pos - inBeg;
    root->left = build(preBeg + 1, preBeg + leftLens, preEnd, pos);
    root->right = build(preBeg + leftLens, preEnd, pos + 1, inEnd);

    return root;
}


int main() {
    cout << "Input the number of nodes in the binary tree:" << endl;
    int nodesNum;
    cin >> nodesNum;
    vector<int> preOrder(nodesNum), inOrder(nodesNum);
    cout << "Input the preOrder traversal sequence:" << endl;
    for (int i = 0; i < nodesNum; ++i) {
        cin >> preOrder[i];
    }
    cout << "Input the inOrder traversal seqence:" << endl;
    for (int i = 0; i < nodesNum; ++i) {
        cin >> inOrder[i];
    }

    TreeNode *root = build(preOrder.begin(), preOrder.end(), inOrder.begin(), inOrder.end());


    return 0;
}
