#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int t, h, m;
    scanf("%d%d:%d", &t, &h, &m);
    if (t == 12) {
        if (h / 10 >= 2) {
            if (h % 10 == 0) h = 10;
            else h = h % 10;
        }
        if (h / 10 == 1 && h % 10 >= 3) h = 10;
        if (h == 0) h = 1;
    } else { // 24
        if (h / 10 >= 3) h = h % 10;
        else if (h > 23) h = 20;
    }
    if (m > 59) m = m % 10;
    printf("%02d:%02d\n", h, m);
    return 0;
}
