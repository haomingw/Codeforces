#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int k, r;
    cin >> k >> r;
    int t;
    for (int i = 1; i <= 10; i++) {
        t = (k * i) % 10;
        if (t == r || t == 0) return !printf("%d\n", i);
    }
    return 0;
}
