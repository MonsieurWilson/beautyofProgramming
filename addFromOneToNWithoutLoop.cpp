#include <iostream>

using namespace std;

class Sum {
public:
    Sum() {
        ++N;
        sum += N;
    }
    static void reset() {
        sum = N = 0;
    }
    static int getSum() {
        return sum;
    }
private:
    static int N;
    static int sum;
};

int Sum::sum = 0;
int Sum::N = 0;

int main() {
    int n;
    while (cin >> n) {
        Sum::reset();
        Sum *p = new Sum[n];
        cout << p[n].getSum() << endl;
        delete[] p;
    }
    return 0;
}
