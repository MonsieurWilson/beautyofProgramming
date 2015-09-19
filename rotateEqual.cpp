#include <iostream>
#include <string>

using namespace std;

bool rotateEqual(const string &src, const string &dst) {
    int lensS = src.size(), lensD = dst.size();
    bool ret = false;
    for (int i = 0; i < lensD; ++i) {
        int j = 0;
        for (; j < lensS; ++j) {
            if (dst[(i + j) % lensD] != src[j]) {
                break;
            }
        }
        if (j == lensS) {
            ret = true;
            break;
        }
    }
    return ret;
}

int main() {
    string src, dst;
    cout << "Input the source string:" << endl;
    cin >> src;
    cout << "Input the destination string:" << endl;
    cin >> dst;
    bool ret = rotateEqual(src, dst);
    cout << (ret ? "True" : "False") << endl;

    return 0;
}
