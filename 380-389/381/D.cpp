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

const int maxn = 2e5 + 5;
int a[maxn], w[maxn], ans[maxn], ct[maxn];
ll d[maxn];
vector<int> g[maxn], path;

int dfs(int v) {
    int nb = 0;
    path.push_back(v);
    for (int u : g[v]) {
        d[u] = d[v] + w[u];
        nb += dfs(u);
    }
    int l = 0, r = path.size() - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (d[v] - d[path[m]] > a[v]) l = m + 1;
        else r = m;
    }
    ans[v] = nb;
    if (path[l] != v) nb++, ct[path[l]]++;
    path.pop_back();
    return nb - ct[v];
}

int main() {
    int n; scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i + 1]);
    int p;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &p, &w[i]);
        g[p].push_back(i);
    }
    dfs(1);
    REPP(i, 1, n + 1) cout << ans[i] << " "; cout << endl;
    return 0;
}
