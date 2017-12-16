#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, sum;
    for (int i = 0; i < n - 1; i++) {
        sum = a[i] + a[i + 1];
        if (sum >= k) continue;
        ans += k - sum;
        // clog << k - sum << endl;
        a[i + 1] += k - sum;
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}

