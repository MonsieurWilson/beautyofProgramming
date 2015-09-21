#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Data structure.
struct TreeNode {
    int leafNum;
    unordered_map<char, TreeNode *> leafNodes;
    TreeNode(): leafNum(0) {}
    TreeNode(const int &val): leafNum(val) {}
};

class Trie {
public:
    static TreeNode *crtTree(const vector<string> &dict) {
        TreeNode *root = new TreeNode(), *ptr;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            string s = *it;
            ptr = root;
            for (int idx = 0; idx < s.size(); ++idx) {
                if (!ptr->leafNodes.count(s[idx])) {
                    ptr->leafNodes[s[idx]] = new TreeNode();
                }
                ptr = ptr->leafNodes[s[idx]];
                ++ptr->leafNum;
            }
        }
        return root;
    }
};

class Solution {
public:
    static int countPreNum(TreeNode *root, const string &s) {
        int idx = 0;
        while (idx < s.size() && root->leafNodes.count(s[idx])) {
            root = root->leafNodes[s[idx++]];
        }
        if (idx == s.size()) {
            return root->leafNum;
        }
        else {
            return 0;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> dict;
    for (int idx = 1; idx <= n; ++idx) {
        string word;
        cin>>word;
        dict.push_back(word);
    }
    TreeNode *root = Trie::crtTree(dict);
    int m;
    cin>>m;
    for (int num = 1; num <= m; ++num) {
        string s;
        cin>>s;
        cout<<Solution::countPreNum(root, s)<<endl;
    }
    return 0;
}
