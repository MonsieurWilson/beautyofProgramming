#include <iostream>
#include <string>

using namespace std;

bool increment(string &num, const int bits) {
    int carry = 1, N = num.size();
    int i = 1;
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

int print1ToNNumbers(const int bits) {
    if (bits <= 1) {
        return -1;
    }
    string num(20, '0');
    while (increment(num, bits)) {
        printWithoutLedingZero(num);
        cout << endl;
    }
    return 0;
}

int main() {
    int bits;
    while (cin >> bits) {
        int status = print1ToNNumbers(bits);
        if (status == -1) {
            cout << "Invalid input." << endl;
        }
    }
    return 0;
}
