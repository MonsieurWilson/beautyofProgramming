#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    const char *fname = "tmp";
    fstream infile(fname);
    string line, ret;
    int cnt = 0;
    srand(time(NULL));
    while (getline(infile, line)) {
        ++cnt;
        if (rand() % cnt == 0) {
            ret = line;
        }
    }
    infile.close();
    cout << ret << endl;
    return 0;
}
