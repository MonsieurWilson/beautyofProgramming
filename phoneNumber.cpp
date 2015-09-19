#include <iostream>
#include <vector>

using namespace std;

int main() {
    char c[10][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    vector<int> total{0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    cout << "Input the bits of the phone number:" << endl;
    int bits;
    cin >> bits;
    vector<int> nums(bits), ans(bits, 0);
    for (int i = 0; i < bits; ++i) {
        cin >> nums[i];
    }

    int k = 0;
    while (true) {
        cout << "The word is:" << endl;
        for (int i = 0; i < bits; ++i) {
            cout << c[nums[i]][ans[i]];
        }
        cout << endl;
        int k = bits - 1;
        while (k >= 0) {
            if (ans[k] < total[nums[k]] - 1) {
                ++ans[k];
                break;
            }
            else {
                ans[k--] = 0;
            }
        }
        if (k < 0) {
            break;
        }
    }

    return 0;
}
