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

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
vector<int> g[maxn];
int dp[maxn][2];
bool vis[maxn];

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

void dfs(int u) {
    // 0: white, 1: black
    if (vis[u]) return;
    vis[u] = true;
    dp[u][0] = dp[u][1] = 1;
    for (int v : g[u]) if (!vis[v]) {
        dfs(v);
        dp[u][0] = mul(dp[u][0], add(dp[v][0], dp[v][1]));
        dp[u][1] = mul(dp[u][1], dp[v][0]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int x, y;
    REP(i, n - 1) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int ans = add(dp[1][0], dp[1][1]);
    cout << ans << endl;
    return 0;
}
