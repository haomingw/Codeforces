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

const int maxn = 7005;
ll a[maxn];

void solve() {
    int n;
    cin >> n;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    map<ll, ll> mp;
    mp[a[n - 1]]++;
    ll ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        REP(j, i) if (a[i] > 0 && mp.count(a[i] * a[j]))
            ans += mp[a[i] * a[j]];
        mp[a[i]]++;
    }
    if (mp.count(0)) {
        ans += mp[0] * (mp[0] - 1) / 2 * (n - mp[0]);
        if (mp[0] > 2) ans += mp[0] * (mp[0] - 1) * (mp[0] - 2) / 6;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
