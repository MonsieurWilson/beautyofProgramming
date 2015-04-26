/*
 * Islands Travel
 * Microsoft 2015
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, num;
    Point():x(0), y(0), num(0){}
    Point(const int &a, const int &b, const int &c):x(a), y(b), num(c){}
    friend bool operator < (const Point &a, const Point &b) {
        return a.x < b.x;
    }
};

const int MAX = 100000;
vector<pair<int, int> > graph[MAX];
vector<Point> points;
int v[MAX];
vector<int> dist;

void build(const int &N) {
    sort(points.begin(), points.end());
    for (int idx = 0; idx < N; ++idx) {
        int next = idx + 1;
        while (next < N && points[next].x == points[idx].x) {
            int a = points[idx].num, b = points[next].num;
            graph[a].push_back(make_pair(b, 0));
            graph[b].push_back(make_pair(a, 0));
            ++next;
        }
        if (idx > 0) {
            int a = points[idx].num, b = points[idx - 1].num;
            graph[a].push_back(make_pair(b, points[idx].x - points[idx - 1].x));
            graph[b].push_back(make_pair(a, points[idx].x - points[idx - 1].x));
        }
        idx = next - 1;
    }
}

int spfa(const int &N) {
    queue<int> q;
    q.push(0);
    v[0] = 1;
    dist[0] = 0;
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        for (int i = graph[idx].size() - 1; i >= 0; --i) {
            int num = graph[idx][i].first;
            if (dist[idx] + graph[idx][i].second < dist[num]) {
                dist[num] = dist[idx] + graph[idx][i].second;
                if (!v[num]) {
                    v[num] = 1;
                    q.push(num);
                }
            }
        }
        v[idx] = 0;
    }
    return dist[N - 1];
}

int main() {
    int N;
    cin>>N;
    points = vector<Point>(N);
    for (int idx = 0; idx < N; ++idx) {
        cin>>points[idx].x>>points[idx].y;
        points[idx].num = idx;
    }
    memset(v, 0, sizeof(v));
    dist = vector<int>(N, 0x7FFFFFFF);
    build(N);
    for (int idx = 0; idx < N; ++idx {
        swap(points[idx].x, points[idx].y);
    }
    build(N);
    cout<<spfa(N)<<endl;
    return 0;
}
