#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <climits>
#define LL long long

using namespace std;

int graph[1001][1001];

int dijkstra(const int &N, const int &S, const int &T) {
    vector<bool> visit(N + 1, false);
    vector<int> lowcost(N + 1, 0);
    visit[S] = true;
    for (int idx = 1; idx <= N; ++idx) {
        lowcost[idx] = graph[S][idx] > 0 ? graph[S][idx] : INT_MAX;
    }
    for (int num = 1; num < N; ++num) {
        int minPath = INT_MAX, index = -1;
        for (int idx = 1; idx <= N; ++idx) {
            if (!visit[idx] && lowcost[idx] < minPath) {
                minPath = lowcost[idx];
                index = idx;
            }
        }
        if (index == T) return lowcost[T];
        visit[index] = true;
        for (int idx = 1; idx <= N; ++idx) {
            if (!visit[idx] && graph[index][idx] > 0) {
                lowcost[idx] = min(lowcost[index] + graph[index][idx], lowcost[idx]);
            }
        }

    }
    return lowcost[T];
}

int main() {
    ios::sync_with_stdio(false);
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    memset(graph, -1, sizeof(graph));
    for (int r = 1; r <= N; ++r) {
        graph[r][r] = 0;
    }
    for (int m = 1; m <= M; ++m) {
        int ui, vi, leni;
        cin >> ui >> vi >> leni;
        graph[ui][vi] = leni;
    }
    cout << dijkstra(N, S, T) << endl;
    return 0;
}
