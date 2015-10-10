#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename Object>
bool isPopOrder(const vector<Object> &inorder, const vector<Object> &poporder) {
    int N = inorder.size();
    if (poporder.size() != N) {
        return false;
    }
    else if (N == 0) {
        return true;
    }
    stack<Object> st;
    int index = 0;
    for (int i = 0; i < N;) {
        while (st.empty() || st.top() != poporder[index] && i < N) {
            st.push(inorder[i++]);
        }
        while (!st.empty() && st.top() == poporder[index]) {
            ++index;
            st.pop();
        }
    }
    return index == N;
}

int main() {
    int T;
    cin >> T;
    for (int num = 1; num <= T; ++num) {
        vector<int> inorder, poporder;
        string ele;
        while (cin >> ele && ele != "#") {
            inorder.push_back(stoi(ele));
        }
        while (cin >> ele && ele != "#") {
            poporder.push_back(stoi(ele));
        }
        bool ret = isPopOrder(inorder, poporder);
        cout << (ret ? "true" : "false") << endl;
    }

    return 0;
}
