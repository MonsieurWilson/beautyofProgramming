#include <iostream>

using namespace std;

int calGCD(int a, int b) {
    int ret = 1;
    while (b) {
        if (a % 2 == 0 && b % 2 == 0) {
            ret <<= 1;
            a >>= 1;
            b >>= 1;
        }
        else if (a % 2 == 0 && b % 2) {
            a >>= 1;
        }
        else if (b % 2 == 0 && a % 2) {
            b >>= 1;
        }
        else {
            int tmp = b;
            b = a - b;
            a = tmp;
        }
        if (a < b) {
            swap(a, b);
        }
    }
    return ret * a;
}

int main() {
    int a, b;
    cout << "Input two numbers:" << endl;
    while (cin >> a >> b) {
        cout << "The GCD is: " << endl << calGCD(a, b) << endl;
    }
    return 0;
}
