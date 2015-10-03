#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Matrix.h"

class Fibonacci {
public:
    int genFibonacci(const int &n) {
        // F(n) = F(n - 1) + F(n - 2)
        // O(N) method
        int tmp1, tmp2, ret;
        tmp1 = 0;
        tmp2 = 1;
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        for (int i = 2; i <= n; ++i) {
            ret = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = ret;
        }
        return ret;
    }

    int genFibonacciII(int n) {
        // [F(n) F(n - 1)] = [F(n - 1) F(n - 2)] * A
        // A = [1, 1; 1, 0]
        // F(n) = F(1) * An[0][0] + F(0) * An[1][0]
        // O(long(N)) method
        int F0 = 0, F1 = 1;
        if (n == 0) {
            return F0;
        }
        else if (n == 1) {
            return F1;
        }
        Matrix<int> A(2, 2);
        A[0][0] = 1;
        A[0][1] = 1;
        A[1][0] = 1;
        Matrix<int> An = matPow(A, n - 1);
        return F1 * An[0][0] + F0 * An[1][0];
    }

};

int main() {
    Fibonacci f;
    cout << "Input the value of number n:" << endl;
    int n;
    while (cin >> n) {
        printf("The %dth fibonacci number is: %d\n", n, f.genFibonacciII(n));
    }

    return 0;
}
