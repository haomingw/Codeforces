#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll b, d, s;
    cin >> b >> d >> s;
    ll a[3] = {b, d, s};
    sort(a, a + 3);
    ll bias = 0, ans;
    if (a[0] == a[2]) bias = 0;
    else if (a[1] == a[2]) bias = 1;
    else bias = 2;

    ans = 2 * a[2] - a[0] - a[1] - bias;
    cout << ans << endl;
    return 0;
}
