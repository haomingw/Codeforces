#include <iostream>
#include <cstdio>
#include <cmath>
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

int main() {
    ll n, m, k, x, s;
    cin >> n >> m >> k;
    cin >> x >> s;
    ll a[m], b[m], c[k], d[k];
    REP(i, m) cin >> a[i];
    REP(i, m) cin >> b[i];
    REP(i, k) cin >> c[i];
    REP(i, k) cin >> d[i];

    ll ans = x * n;
    int t, mana;
    for (int i = -1; i < m; i++) {
        t = a[i], mana = b[i];
        if (mana > s || i == -1) { t = x; mana = 0; }
        int ind = upper_bound(d, d + k, s - mana) - d - 1;
        int gen = ind >= 0 ? c[ind] : 0;
        ans = min(ans, t * (n - gen));
    }
    cout << ans << endl;
    return 0;
}
