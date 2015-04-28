#ifndef GENERATEPRIME
#define GENERATEPRIME

class Generate {
public:
    void generatePrime(const int &N) {
        int p[N] = {0};
        for (int i = 1; i < N; i += 2) {
            p[i] = 1;
        }
        for (int i = 2; i < N; ++i) {
            for (int j = i * i; j < N; j += i) {
                p[j] = 0;
            }
        }
        p[2] = 1;
        for (int i = 0; i < N; ++i) {
            if (p[i]) {
                cout<<i<<endl;
            }
        }
    }
};

#endif
