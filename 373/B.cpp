#include <iostream>
#include <string>
#include <bitset>
using namespace std;

#define T 100000

int solve(bitset<T>& a, int n) {
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            if (i % 2 == 0)
                even++;
            else
                odd++;
        }
    }
    return a.count() - min(odd, even);
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bitset<T> x1, x2, sb;
    bool f = true;
    for (int i = 0; i < n; i++) {
        sb[n - 1 - i] = s[i] == 'r';
        x1[n - 1 - i] = f;
        x2[n - 1 - i] = !f;
        f = !f;
    }
    int a = solve((x1^=sb), n), b = solve((x2^=sb), n);
    cout << min(a, b) << endl;
    return 0;
}
