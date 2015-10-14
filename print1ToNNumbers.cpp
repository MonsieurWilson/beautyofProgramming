#include <iostream>
#include <string>

using namespace std;

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
    int bits;
    while (cin >> bits) {
        print1ToNNumbers(bits);
    }
    return 0;
}
