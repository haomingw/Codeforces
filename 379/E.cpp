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

const int N = 2e5 + 10;
vector<vector<int> > g, g1;
int color[N], p[N], visited[N], dp[N];
int ans = 0, cnt = 0;

void unite(int v, int col, int id) {
    if (visited[v]) return;
    if (color[v] != col) return;
    visited[v] = 1;
    p[v] = id;
    REP(i, SIZE(g[v])) {
        int to = g[v][i];
        unite(to, col, id);
    }
}

void dfs(int v, int parent = -1) {
    int mx1 = 0, mx2 = 0;
    REP(i, SIZE(g1[v])) {
        int to = g1[v][i];
        if (to == parent) continue;
        dfs(to, v);
        int val = dp[to] + 1;
        mx2 = max(mx2, val);
        if (mx1 < mx2) swap(mx1, mx2);
    }
    dp[v] = mx1;
    ans = max(ans, mx1 + mx2);
}

int main() {
    int n, a, b;
    cin >> n;
    REP(i, n) cin >> color[i];
    REP(i, n) p[i] = i;
    g.resize(n);
    REP(i, n - 1) {
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    REP(i, n) if (!visited[i]) unite(i, color[i], cnt++);
    g1.resize(cnt);
    REP(i, n) REP(j, SIZE(g[i])) {
        int to = g[i][j];
        if (p[i] != p[to])
            g1[p[i]].push_back(p[to]);
    }
    dfs(0);
    cout << (ans + 1) / 2 << endl;
    return 0;
}
