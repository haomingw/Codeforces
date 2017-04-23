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

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;
const int maxn = 105;
int e[maxn], s[maxn];
ll g[maxn][maxn];
double dist[maxn][maxn];

void solve() {
    int n, Q;
    cin >> n >> Q;
    REP(i, n) cin >> e[i] >> s[i];
    int x, y;
    REP(i, n) REP(j, n) {
        cin >> x;
        if (x == -1) g[i][j] = inf;
        else g[i][j] = x;
    }
    REP(i, n) g[i][i] = 0;
    REP(k, n) REP(i, n) REP(j, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    REP(i, n) REP(j, n) {
        if (g[i][j] <= e[i]) dist[i][j] = 1. * g[i][j] / s[i];
        else dist[i][j] = inf;
    }
    REP(k, n) REP(i, n) REP(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    REP(i, Q) {
        cin >> x >> y;
        x--, y--;
        printf("%.8f ", dist[x][y]);
    }
    printf("\n");
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
