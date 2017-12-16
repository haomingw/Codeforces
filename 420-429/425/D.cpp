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

const int deg = 18;
const int maxn = 1e5 + 5;
vector<int> g[maxn];
int parent[maxn][deg], h[maxn];

void dfs(int u) {
    for (int v : g[u]) {
        if (h[v] != -1) continue;
        h[v] = h[u] + 1;
        parent[v][0] = u;
        REP(i, deg - 1) {
            if (parent[v][i] == -1) break;
            parent[v][i + 1] = parent[parent[v][i]][i];
        }
        dfs(v);
    }
}

int up(int u, int d) {
    for (int i = 0; d; i++, d >>= 1) {
        if (d & 1) u = parent[u][i];
    }
    return u;
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = up(u, h[u] - h[v]);
    if (u == v) return u;
    for (int i = deg - 1; i >= 0; i--)
        if (parent[u][i] != parent[v][i])
            u = parent[u][i], v = parent[v][i];
    return parent[u][0];
}

int dist(int u, int v) {
    int m = lca(u, v);
    return h[u] + h[v] - 2 * h[m];
}

int main() {
    int n, p, q;
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p);
        g[p].push_back(i);
        g[i].push_back(p);
    }
    REPP(i, 1, n + 1) {
        h[i] = -1;
        REP(j, deg) parent[i][j] = -1;
    }
    h[1] = 0;
    dfs(1);

    int a, b, c, ans = 0;
    REP(i, q) {
        scanf("%d%d%d", &a, &b, &c);
        // number of intersession edges is
        // (dist(s, f) + dist(t, f) - dist(s, t)) / 2
        int la = dist(a, b), lb = dist(b, c), lc = dist(c, a);
        ans = 1 + (la + lb + lc) / 2 - min(la, min(lb, lc));
        cout << ans << endl;
    }
    return 0;
}
