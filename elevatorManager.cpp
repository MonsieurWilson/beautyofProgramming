#include <iostream>
#include <vector>

using namespace std;

int manager(const vector<int> &down) {
    int N1 = 0, N2 = down[0], N3 = 0;
    int target = 1, minMoves = 0;
    int nFloors = down.size();
    for (int i = 1; i < nFloors; ++i) {
        N3 += down[i];
        minMoves += i * down[i];
    }
    for (int i = 1; i < nFloors; ++i) {
        if (N1 + N2 < N3) {
            target = i + 1;
            minMoves += N1 + N2 - N3;
            N1 += N2;
            N2 = down[i];
            N3 -= down[i];
        }
        else {
            break;
        }
    }
    return target;
}

int main() {
    vector<int> down;
    int ele;
    while (cin >> ele) {
        down.push_back(ele);
    }
    cout << "The elevator should stop at the " << manager(down) << " floor." << endl;
    return 0;
}
