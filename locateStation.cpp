#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Point {
    int x, y;
    Point():x(0), y(0){}
    Point(const int &a, const int &b):x(a), y(b){}
};

int manDist(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

long long eucDist(const Point &a, const Point &b) {
    long long xsquare = (a.x - b.x) * (a.x - b.x), ysquare = (a.y - b.y) * (a.y - b.y);
    return xsquare + ysquare;
}

long long minCost(const int &N, const int &M, const vector<Point> &user, const vector<Point> &com, const vector<Point> &center) {
    long long ret = 0;
    for (int num = 0; num < center.size(); ++num) {
        long long tmp = 0;
        for (int idx = 0; idx < user.size(); ++idx) {
            tmp += eucDist(user[idx], center[num]);
        }
        int cost = INT_MAX;
        for (int idx = 0; idx < com.size(); ++idx) {
            cost = min(cost, manDist(com[idx], center[num]));
        }
        tmp += cost;
        if (ret == 0 || ret > tmp) ret = tmp;
    }
    return ret;
}

int main() {
    int T;
    cin>>T;
    int num = 1;
    while (num <= T) {
        int N, M, A, B;
        cin>>N>>M>>A>>B;
        vector<Point> user(A);
        vector<Point> com(B);
        vector<Point> center;
        long long xm = 0, ym = 0;
        for (int idx = 0; idx < A; ++idx) {
            cin>>user[idx].x>>user[idx].y;
            xm += user[idx].x;
            ym += user[idx].y;
        }
        center.push_back(Point(xm / A, ym / A));
        center.push_back(Point(xm / A + 1, ym / A));
        center.push_back(Point(xm / A, ym / A + 1));
        center.push_back(Point(xm / A + 1, ym / A + 1));
        for (int idx = 0; idx < B; ++idx) {
            cin>>com[idx].x>>com[idx].y;
        }
        cout<<"Case #"<<num++<<": "<<minCost(N, M, user, com, center)<<endl;
    }
    return 0;
}
