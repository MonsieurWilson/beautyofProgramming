#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int knapSack(const int &N, const int &M, const vector<int> &need, const vector<int> &value) {
    // 01 knapSack.
    for (int n = 0; n < N; ++n) {
        for (int m = M; m >= need[n]; --m) {
            // dp(i, j) = max{dp(i - 1, j - need(i)) + value(i), dp(i - 1, j)}
            dp[m] = max(dp[m], dp[m - need[n]] + value[n]);
        }
    }
    return dp[M];
}

int completeKnapStack(const int &N, const int &M, const vector<int> &need, const vector<int> &value) {
    // 0K knapSack.
    for (int n = 0; n < N; ++n) {
        for (int m = need[n]; m <= M; ++m) {
            // dp(i, j) = max{dp(i, j - need(j)) + value(i), dp(i - 1, j)}
            dp[m] = max(dp[m], dp[m - need[n]] + value[n]);
        }
    }
    return dp[M];
}

int main() {
    int N, M;
    cin>>N>>M;
    vector<int> need(N), value(N);
    for (int idx = 0; idx < N; ++idx) {
        cin>>need[idx]>>value[idx];
    }
    dp = vector<int>(M + 1, 0);
    cout<<knapSack(N, M, need, value)<<endl;
    //cout<<completeKnapStack(N, M, need, value)<<endl;
    return 0;
}
