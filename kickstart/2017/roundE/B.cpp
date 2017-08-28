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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 5005;
int v[maxn];
map<int, int> mp;
set<int> sides;

bool can(int x, int a, int b) {
    if (a == b) return false;
    if (a > b) swap(a, b);
    return 2 * x - b + a > 0;
}

void solve() {
    mp.clear();
    sides.clear();
    int n, t; cin >> n;
    REP(i, n) {
        cin >> t;
        mp[t] += 1;
        sides.insert(t);
    }
    ll cas, ans = 0;
    for (int x : sides) if (mp[x] >= 2) {
        cas = 1LL * mp[x] * (mp[x] - 1) / 2;
        n = 0;
        for (int y : sides) if (x != y) v[n++] = y;
        assert(n == SZ(sides) - 1);
        REP(i, n) REPP(j, i + 1, n) {
            if (can(x, v[i], v[j])) ans += cas * mp[v[i]] * mp[v[j]];
        }
    }
    for (int x : sides) if (mp[x] >= 3) {
        cas = 1LL * mp[x] * (mp[x] - 1) * (mp[x] - 2) / 6;
        for (int y : sides) if (x != y && can(x, x, y)) ans += cas * mp[y];
    }
    cout << ans << endl;
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
