#include "Algorithm.h"
#include "HeapSort.h"
#include <vector>

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

template <typename Object>
class Sum {
public:
    Object operator () (const Object &o1, const Object &o2) {
        return o1 + o2;
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
    HeapSort<int> heap_sort;
    vector<int> vec;
    int ele;
    cout << "Input the vector's elements: " << endl;
    while (cin >> ele) {
        vec.push_back(ele);
    }
    heap_sort(vec);
    cout << "After sorting, the vector's elements are: " << endl;
    for (auto v: vec) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
