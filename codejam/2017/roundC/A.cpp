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
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PI 3.14159265358979323846264338328

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int maxn = 1005;
ll a[maxn];
pll p[maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    ll r, h;
    REP(i, n) {
        cin >> r >> h;
        p[i] = MP(r, h);
    }
    sort(p, p + n);
    ll t, sum = 0, ans = 0;
    for (int i = n - 1; i >= k - 1; i--) {
        r = p[i].first, h = p[i].second;
        t = r * r + 2 * r * h;
        for (int j = i - 1; j >= 0; j--) {
            a[i - 1 - j] = 2 * p[j].first * p[j].second;
        }
        sort(a, a + i, greater<ll>());
        REP(j, k - 1) t += a[j];
        ans = max(ans, t);
    }
    printf("%.10f\n", ans * PI);
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
