// KMP string matching.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int kmp(const string &pattern, const string &source) {
        // KMP algorithm.
        int n = source.size(), m = pattern.size();
        int ret = 0;
        if (m == 0) return ret;
        // Calculating prefix function for pattern.
        vector<int> prefix(m, 0);
        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1];
            while (prefix[i] > 0 && pattern[prefix[i]] != pattern[i]) {
                prefix[i] = prefix[prefix[i] - 1];
            }
            if (pattern[prefix[i]] == pattern[i]) {
                prefix[i]++;
            }
        }
        for (int idx = 0, p = 0; idx < n; idx++) {
            // When failed to match the index p of pattern, 
            // then we jump to the index prefix[p - 1].
            while (p > 0 && pattern[p] != source[idx]) {
                p = prefix[p - 1];
            }
            // Matching successfully.
            if (pattern[p] == source[idx]) {
                p++;
            }
            // Having reached the tail of the pattern.
            if (p == m) {
                ++ret;
                // Jumping to the next matching index.
                p = prefix[p - 1];
            }
        }
        return ret;
    }
};

int main() {
    int N;
    (cin>>N).get();
    for (int num = 1; num <= N; ++num) {
        string pattern, source;
        getline(cin, pattern);
        getline(cin, source);
        cout<<Solution::kmp(pattern, source)<<endl;
    }
    return 0;
}
