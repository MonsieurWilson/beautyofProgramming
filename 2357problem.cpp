#include <iostream>
#include <climits>

using namespace std;

int cal(const int &N) {
    int ret = 1;
    int idx[] = {2, 3, 5, 7}, val[] = {1, 1, 1, 1};
    for (int num = 2; num <= N; ++num) {
        ret = INT_MAX;
        for (int i = 0; i < 4; ++i) {
            ret = min(ret, val[i] * idx[i]);
        }
        for (int i = 0; i < 4; ++i) {
            if (val[i] * idx[i] == ret) {
                ++val[i];
            }
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    for (int n = 1; n <= N; ++n) {
        cout<<cal(n)<<" ";
    }
    cout<<endl;
}
