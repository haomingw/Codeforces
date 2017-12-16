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

const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll ts, tf, t;
    int n;
    cin >> ts >> tf >> t >> n;
    REP(i, n) cin >> a[i];
    ll p = ts;
    REP(i, n) {
        b[i + 1] = max(p, a[i]);
        p = b[i + 1] + t;
    }
    b[0] = ts - t, p = 0;
    ll ans = b[n] + t, minx = 1e13;
    if (ans <= tf - t) return !printf("%lld\n", ans);
    if (a[0] > ts) return !printf("%lld\n", ts);
    while (p < n) {
        if (b[p] + t > tf - t) break;
        ll x = b[p] + t - a[p] + 1;
        if (x <= 0) return !printf("%lld\n", b[p] + t);
        if (x < minx) minx = x, ans = a[p] - 1;
        x = a[p];
        while (a[p] == x) p++;
    }
    cout << ans << endl;
    return 0;
}
