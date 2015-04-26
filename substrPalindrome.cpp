#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define MOD 100007;

using namespace std;

int dp[1010][1010];

int palindromeNum(const string &s, const int &beg, const int &end) {
    if (dp[beg][end] != -1) {
        return dp[beg][end];
    }
    if (end < beg) {
        return dp[beg][end] = 0;
    }
    else if (end == beg) {
        return dp[beg][end] = 1;
    }
    int &ret = dp[beg][end];
    ret = (palindromeNum(s, beg + 1, end) + palindromeNum(s, beg, end - 1)) % MOD;
    if (s[beg] == s[end]) {
        ++ret;
    }
    else {
        ret -= palindromeNum(s, beg + 1, end - 1);
    }
    ret %= MOD;
    return ret;
}

int palindromeNum_dp(const string &s) {
    int dp[1001][1001];
    memset(dp, -1, sizeof(dp));
    int lens = s.size();
    for (int r = 0; r < lens; ++r) {
        dp[r][r] = 1;
    }
    for (int l = 2; l <= lens; ++l) {
        for (int r = lens - l; r >= 0; --r) {
            int beg = r, end = r + l - 1;
            dp[beg][end] = (dp[beg + 1][end] + dp[beg][end - 1]) % MOD;
            if (s[beg] == s[end]) {
                ++dp[beg][end];
            }
            else if (end - beg > 1) {
                dp[beg][end] -= dp[beg + 1][end - 1];
            }
        }
    }
    return dp[0][lens - 1];
}

int main() {
    int T;
    (cin>>T).get();
    int num = 1;
    while (num <= T) {
        string s;
        getline(cin, s);
        memset(dp, -1, sizeof(dp));
        cout<<"Case #"<<num++<<": "<<palindromeNum(s, 0, s.size() - 1)<<endl;
        cout<<"Case #"<<num++<<": "<<palindromeNum_dp(s)<<endl;
    }
    return 0;
}
