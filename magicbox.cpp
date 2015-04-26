/*
 * Magic Box
 * Microsoft 2015
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <string>
#define LL long long;

using namespace std;

int maxBalls(const int &x, const int &y, const int &z, const string &seq) {
    int ret = 0, temp = 0;
    unordered_map<char, int> umap;
    int arr[] = {x, y, z};
    vector<int> pattern(arr, arr + 3);
    sort(pattern.begin(), pattern.end());
    for (int idx = 0; idx < seq.size(); ++idx) {
        ++temp;
        ++umap[seq[idx]];
        int cr = umap['R'], cy = umap['Y'], cb = umap['B'];
        int arr[] = {abs(cr - cy), abs(cr - cb), abs(cy - cb)};
        vector<int> source(arr, arr + 3);
        sort(source.begin(), source.end());
        if (pattern == source) {
            ret = max(ret, temp);
            umap.clear();
            temp = 0;
        }
    }
    return max(temp, ret);
}

int main() {
    ios::sync_with_stdio(false);
    int x, y, z;
    cin>>x>>y>>z;
    string seq;
    cin>>seq;
    cout<<maxBalls(x, y, z, seq)<<endl;
    return 0;
}
