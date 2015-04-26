#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000;

int graph[MAX][MAX] = {0};
int v[MAX] = {0}, lowcost[MAX] = {0}, closest[MAX] = {0};

int prim(const int &N) {
    // Initialize.
    for (int idx = 1; idx < N; ++idx) {
        lowcost[idx] = graph[0][idx];
        closest[idx] = 0;
    }
    for (int i = 1; i < N; ++i) {
        int minPath = 0x7FFFFFFF;
        int next = 0;
        for (int j = 0; j < N; ++j) {
            if (!v[j] && lowcost[j] < minPath) {
                next = j;
                minPath = lowcost[j];
            }
        }
        v[next] = 1;
        for (int j = 0; j < N; ++j) {
            if (!v[j] && lowcost[j] > graph[next][j]) {
                closest[j] = next;
                lowcost[j] = graph[next][j];
            }
        }
    }
    int ret = 0;
    for (int idx = 1; idx < N; ++idx) {
        ret += lowcost[idx];
    }
    return ret;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            scanf("%d", &graph[r][c]);
        }
    }
    printf("%d\n", prim(N));
    return 0;
}
