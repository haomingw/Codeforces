#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 200010;
char c[maxn];

bool pass(char& a) {
    return a >= '0' && a < '5';
}

int main() {
    int n, t;
    cin >> n >> t;
    cin >> c;
    // scanf("%*d%d%s",&t,c);

    int p = 0, cr = 0, pp;
    while (c[p] != '.') p++;
    pp = p;
    p++;
    while (pass(c[p])) p++; // Last digit to considerate
    if (c[p] == '\0') return !printf("%s\n", c);

    int v;
    while (t--) {
        v = c[p] - '0';
        if (v >= 5) {
            c[p] = '\0';
            if (c[p - 1] != '.') {
                c[p - 1] += 1;
            } else {
                c[p - 1] = '\0';
                cr = 1;
                break;
            }
            p--;
        } else
            break;
    }
    // consider case when cr == 1
    if (cr == 1) {
        for (pp--; pp >= 0; pp--) {
            v = c[pp] - '0' + cr;
            if (v == 10) {
                c[pp] = '0';
                cr = 1;
            } else {
                c[pp] = '0' + v;
                cr = 0;
            }
        }
    }
    if (cr) cout << '1';
    cout << c << endl;
    return 0;
}
