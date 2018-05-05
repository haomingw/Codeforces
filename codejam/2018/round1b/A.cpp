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

const int inf = 1e9;
const int maxn = 1e5 + 5;
int total, n, a[maxn];
vector<pii> d;

int percentage(int x) {
    return int(100.0 * x / total + 0.5);
}

void solve() {
    cin >> total >> n;
    int sum = 0;
    REP(i, n) cin >> a[i];
    REP(i, n) sum += a[i];
    vector<int> targets;
    int x, y, k = total - sum;
    REP(i, n + k) {
        x = percentage(i);
        y = int(100.0 * i / total);
        if (x > y) targets.push_back(i);
    }
    REP(i, n + k) {
        x = lower_bound(ALL(targets), a[i]) - targets.begin();
        int dist = (x < SZ(targets)) ? targets[x] : inf;
        d.push_back(MP(dist - a[i], i));
    }
    sort(ALL(d));
    int rest = k;
    REP(i, SZ(d)) {
        int togo = d[i].first, index = d[i].second;
        if (rest >= togo) rest -= togo, a[index] += togo;
    }
    int ans = 0;
    ans += percentage(rest);
    REP(i, n + k) ans += percentage(a[i]);
    cout << ans << endl;
    REP(i, n + k) a[i] = 0;
    d.clear();
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