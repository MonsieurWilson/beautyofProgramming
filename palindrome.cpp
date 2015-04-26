// Longest palindrome substring.
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    static string preProcess(const string &s) {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++) {
            ret += "#";
            ret += s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }

    static int longestPalindrome(const string &s) {
        // Manacher’s Algorithm
        string T = preProcess(s);
        int n = T.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; ++i) {
            P[i] = (R > i) ? min(R - i, P[2 * C - i]) : 0;
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }
            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        for (int idx = 0; idx < P.size(); ++idx) {
            cout<<P[idx]<<" ";
        }
        cout<<endl;
        return *max_element(P.begin(), P.end());
    }
};

int main() {
    // Input the N.
    int N;
    (cin>>N).get();
    for (int num = 1; num <= N; ++num) {
        string s;
        getline(cin, s);
        cout<<Solution::longestPalindrome(s)<<endl;
    }
    return 0;
}
