#include "Algorithm.h"
#include <vector>
#include <set>

using namespace std;

template <typename Object>
class LessThan {
public:
    bool operator () (const Object &o1, const Object &o2) {
        return o1.beg < o2.beg;
    }
};

template <typename Object>
class BiggerThan {
public:
    bool operator () (const Object &o1, const Object &o2) {
        return o1.beg > o2.beg;
    }
};

struct Interval {
    int beg;
    int end;
    Interval(): beg(0), end(0) {}
    Interval(const int b, const int e): beg(b), end(e) {}
};

ostream &operator << (ostream &o, const Interval &i) {
    o << "[" << i.beg << ", " << i.end << "]";
    return o;
}


int main() {
    set<Interval, BiggerThan<Interval>> hashMap;
    cout << "Input the intervals:" << endl;
    int b, e;
    while (cin >> b >> e) {
        hashMap.insert(Interval(b, e));
    }

    cout << "The elements in the containers:" << endl;
    for (auto it = hashMap.cbegin(); it != hashMap.cend(); ++it) {
        cout << *it << endl;
    }
    

    return 0;
}
