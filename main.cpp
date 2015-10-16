#include <vector>
#include <cmath>
#include <cstdlib>
#include "Algorithm.h"
#include "Sort.h"


using namespace std;

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

int addTwoNums(const int a, const int b) {
    int ret = a ^ b, carry = (a & b) << 1;
    while (carry) {
        int tmp = ret;
        ret ^= carry;
        carry = (carry & tmp) << 1;
    }
    return ret;
}

struct A {
    float f;
    int arr[3];
};

int main() {
    /*
    cout << "Input the vector's elements:" << endl;
    vector<long> nums;
    int ele;
    while (cin >> ele) {
        nums.push_back(ele);
    }

    Sort s;
    s.radixSort(nums);

    cout << "After sorting, the vector's elements are:" << endl;
    for (auto v: nums) {
        cout << v << " ";
    }
    cout << endl;
    */

    cout << sizeof(A) << endl;


    return 0;
}
