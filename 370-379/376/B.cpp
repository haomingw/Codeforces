#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool ans = true;
    int next = 0, tmp;
    for (int i = n - 1; i >= 0; i--) {
        tmp = a[i] - next;
        if (tmp < 0) return !printf("NO\n");
        next = tmp % 2;
    }
    if (next == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
