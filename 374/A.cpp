#include <iostream>
#include <cstdio>
using namespace std;

char c[105];

int main() {
    int n;
    cin >> n;
    scanf("%s", c);
    int ans = 0, cnt = 0, a[105];
    bool f = false;

    for (int i = 0; i < n; i++) {
        if (c[i] == 'B') {
            cnt++;
            f = true;
        } else {
            a[ans] = cnt; // save counter
            if (f) ans++;
            cnt = 0; // clear cnt in the case of 'W'
            f = false;
        }
    }
    if (f) {
        ans++;
        a[ans - 1] = cnt;
    }

    cout << ans << endl;
    if (ans == 0) return 0;
    for (int i = 0; i < ans - 1; i++)
        cout << a[i] << " ";
    cout << a[ans - 1] << endl;
    return 0;
}
