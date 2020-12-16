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

const int maxn = 105;
const int inf = 1e9;
int f[maxn];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int s, d, gas, dist[n][n];
    REP(i, n) REP(j, n) dist[i][j] = inf;
    REP(i, n) dist[i][i] = 0;
    vector<pii> fp;
    REP(i, n + 1) f[i] = i;
    REP(i, m) {
        cin >> s >> d >> gas;
        s--, d--;
        dist[s][d] = min(dist[s][d], gas);
        dist[d][s] = min(dist[d][s], gas);
        if (s > d) swap(s, d);
        f[find(d)] = find(s);
    }
    REP(kk, n) REP(i, n) REP(j, n)
        dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
    REP(i, k) {
        cin >> s >> d;
        s--, d--;
        fp.push_back(MP(s, d));
    }
    for (pii& p : fp) {
        s = p.first, d = p.second;
        if (find(s) != find(0) || find(d) != find(0)) {
            cout << -1 << endl;
            return;
        }
    }
    // ok, calculate the shortedist path
    int dp[k][2];
    int ans = dist[0][fp[0].first];
    memset(dp, 0, sizeof(dp));
    int prev, next;
    REP(i, k) {
        s = fp[i].first, d = fp[i].second;
        if (i == 0) {
            next = fp[i + 1].first;
            dp[i][0] = dist[s][d];
            dp[i][1] = dist[s][next] + dist[next][d];
            continue;
        }
        if (i == k - 1) {
            prev = fp[i - 1].second;
            dp[i][0] = dp[i - 1][0] + dist[prev][s] + dist[s][d];
            dp[i][1] = dp[i - 1][1] + dist[prev][d];
            continue;
        }
        prev = fp[i - 1].second, next = fp[i + 1].first;
        int t1 = dp[i - 1][0] + dist[prev][s] + dist[s][d],
            t2 = dp[i - 1][1] + dist[prev][d];
        dp[i][0] = min(t1, t2);
        t1 = dp[i - 1][0] + dist[prev][s] + dist[s][next] + dist[next][d];
        t2 = dp[i - 1][1] + dist[prev][next] + dist[next][d];
        dp[i][1] = min(t1, t2);
    }
    ans += min(dp[k - 1][0], dp[k - 1][1]);
    cout << ans << endl;
}

int main() {
    int T; cin >> T;
    REP(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
