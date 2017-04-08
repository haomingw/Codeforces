#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll t = k / 2, val = n;
    int cnt = 0;
    ll a[2], b[2];
    b[0] = 1, b[1] = 0;
    while (t > 0) {
        a[0] = a[1] = 0;
        if (val & 1) {
            a[0] += 2 * b[0] + b[1];
            a[1] += b[1];
        } else {
            a[0] += b[0];
            a[1] += 2 * b[1] + b[0];
        }
        b[0] = a[0], b[1] = a[1];
        val = (val - 1) / 2;
        t /= 2, cnt++;
    }
    ll nb = k - (1LL << cnt) + 1;
    if (nb <= b[1]) t = val + 1;
    else t = val;
    ll maxx, minx;
    if (t & 1) maxx = minx = (t - 1) / 2;
    else minx = (t - 1) / 2, maxx = minx + 1;
    cout << maxx << " " << minx << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
