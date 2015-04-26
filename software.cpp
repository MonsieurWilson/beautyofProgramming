/*
 * Professor Q's Software
 * Micsoft 2015
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int MOD = 142857;

vector<int> function(const int &N, const int &M, queue<int> &q, const vector<vector<int> > &E, const unordered_multimap<int, int> &umap) {
    vector<int> ret(N, 0);
    while (!q.empty()) {
        int S = q.front();
        q.pop();
        auto found = umap.equal_range(S);
        if (found.first == found.second) {
            continue;
        }
        for (auto cur = found.first; cur != found.second; ++cur) {
            int num = cur->second;
            ++ret[num];
            ret[num] %= MOD;
            for (int k = 0; k < E[num].size(); ++k) {
                if (umap.count(E[num][k]) > 0) q.push(E[num][k]);
            }
        }
    }
    return ret;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int num = 1; num <= T; ++num) {
        vector<vector<int> > E;
        queue<int> q;
        unordered_multimap<int, int> umap;

        int N, M;
        scanf("%d%d", &N, &M);
        for (int idx = 0; idx < M; ++idx) {
            int tmp;
            scanf("%d", &tmp);
            q.push(tmp);
        }
        for (int idx = 0; idx < N; ++idx) {
            int S, K;
            scanf("%d%d", &S, &K);
            umap.insert(make_pair(S, idx));
            vector<int> line(K, 0);
            for (int j = 0;j < K; ++j) {
                scanf("%d", &line[j]);
            }
            E.push_back(line);
        }
        
        vector<int> ret = function(N, M, q, E, umap);
        for (int idx = 0; idx < N; ++idx) {
            printf("%d ", ret[idx]);
        }
        printf("\n");
    }
    return 0;
}
