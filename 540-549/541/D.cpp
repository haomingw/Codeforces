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
#define REPP(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 1005;
char a[maxn][maxn];
int f[maxn * 2], dp[maxn * 2], color[maxn * 2];
vector<int> g[maxn * 2];

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

int dfs(int u) {
    if (dp[u] > 0) return dp[u];
    int res = 1;
    for (int v : g[u]) {
        res = max(res, dfs(v) + 1);
    }
    dp[u] = res;
    return res;
}

bool dfs2(int u) {
    if (color[u] == 1) return false;
    if (color[u] == 2) return true;
    color[u] = 1;
    for (int v : g[u]) {
        if (!dfs2(v)) return false;
    }
    color[u] = 2;
    return true;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    string s;
    REP(i, n + m) f[i] = i;
    REP(i, n) {
        scanf("%s", a[i]);
        REP(j, m) {
            if (a[i][j] == '=') f[find(i)] = find(f[n + j]);
        }
    }
    REP(i, n) REP(j, m) {
        if (a[i][j] == '=') continue;
        if (a[i][j] == '>') g[find(i)].push_back(find(n + j));
        else g[find(n + j)].push_back(find(i));
    }
    vector<int> groups;
    REP(i, n + m) if (f[i] == i) groups.push_back(i);
    for (int x : groups) {
        if (!dfs2(x)) {
            printf("NO\n");
            return 0;
        }
    }
    for (int x : groups) dfs(x);
    printf("YES\n");
    REP(i, n) printf("%d ", dp[find(i)]);
    printf("\n");
    REP(i, m) printf("%d ", dp[find(n + i)]);
    printf("\n");
    return 0;
}
