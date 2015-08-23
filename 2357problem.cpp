#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int cal(const int &N) {
    vector<int> ret(1, 1);
    int base[] = {2, 3, 5, 7}, idx[] = {0, 0, 0, 0};
    for (int num = 2; num <= N; ++num) {
        int minVal = base[0] * ret[idx[0]];
        for (int i = 1; i < 4; ++i) {
            minVal = min(minVal, base[i] * ret[idx[i]]);
        }

        for (int i = 0; i < 4; ++i) {
            if (base[i] * ret[idx[i]] == minVal) {
                ++idx[i];
            }
        }
        ret.push_back(minVal);
    }
    return ret[ret.size() - 1];
}

int main() {
    int N;
    cin >> N;
    for (int n = 1; n <= N; ++n) {
        cout<<cal(n)<<" ";
    }
    cout<<endl;
}
