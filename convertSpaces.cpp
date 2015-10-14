#include <iostream>
#include <cstring>
#define MAX_LENGTH 100

using namespace std;

void convertSpaces(char *s) {
    int lens = strlen(s);
    if (!lens) {
        return;
    }
    int cnt = 0;
    char *ptr = s;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            ++cnt;
        }
        ++ptr;
    }
    int newLens = lens + 2 * cnt;
    char *src = s + lens, *dst = s + newLens;
    while (dst > src) {
        if (*src != ' ') {
            *dst-- = *src--;
        }
        else {
            --src;
            *dst-- = '0';
            *dst-- = '2';
            *dst-- = '%';
        }
    }
    s[newLens] = '\0';
}

int main() {
    char s[MAX_LENGTH] = {0};
    scanf("%[^\n]s", s);
    convertSpaces(s);
    printf("%s\n", s);
    return 0;
}
