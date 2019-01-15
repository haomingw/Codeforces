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

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int dp[maxn];
bool vis[maxn];

int dfs(int u) {
    if (vis[u]) return dp[u];
    vis[u] = true;
    int depth = 0;
    for (int v : g[u]) {
        depth = max(depth, 1 + dfs(v));
    }
    dp[u] = depth;
    return depth;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int x, y;
    REP(i, m) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    int ans = 0;
    REPP(i, 1, n + 1) ans = max(ans, dfs(i));
    cout << ans << endl;
    return 0;
}
