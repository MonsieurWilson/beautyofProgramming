#include <vector>
#include <cmath>
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

bool increment(string &num, const int bits) {
    int carry = 1, i = 1;
    int N = num.size();
    for (; i <= bits; ++i) {
        int sum = num[N - i] - '0' + carry;
        if (sum >= 10) {
            num[N - i] = sum - 10 + '0';
        }
        else {
            num[N - i] = sum + '0';
            break;
        }
    }
    return i != bits;
}

void printWithoutLedingZero(const string &num) {
    int beg = 0;
    while (num[beg] == '0') {
        ++beg;
    }
    while (beg < num.size()) {
        cout << num[beg++];
    }
}

void print1ToNNumbers(const int bits) {
    string num(20, '0');
    while (increment(num, bits)) {
        printWithoutLedingZero(num);
        cout << endl;
    }
}

int main() {
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
    return 0;
}
