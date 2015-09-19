#include "Algorithm.h"

int main() {
    Algorithm a;
    cout << "Input the size of array:" << endl;
    int lens;
    cin >> lens;
    vector<int> vec(lens);
    cout << "Input the array's elements:" << endl;
    for (int i = 0; i < lens; ++i) {
        cin >> vec[i];
    }
    int ret = a.LISLength_improved(vec);
    cout << "The lis length is: " << ret << endl;

    return 0;
}
