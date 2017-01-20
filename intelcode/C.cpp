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

const int maxn = 2e5 + 10;
int n, m, K;
int x[maxn], y[maxn], pa[maxn], pb[maxn];
vector<int> va[maxn], vb[maxn];
ll ans[maxn];

void dfs(int k1, int k2, int k3, int k4, ll k5) {
    if (k3 == k4) {
        int now = k1 - k2 + m;
        if (pb[now]) return; pb[now] = 1;
        for (int k : vb[now]) {
            ll t = abs(x[k] - k1) + k5;
            if (ans[k] == -1) ans[k] = t;
        }
    } else {
        int now = k1 + k2;
        if (pa[now]) return; pa[now] = 1;
        for (int k : va[now]) {
            ll t = abs(x[k] - k1) + k5;
            if (ans[k] == -1) ans[k] = t;
        }
    }
    int t1 = 0, t2 = 0;
    if (k3 == 1) t1 = n - k1; else t1 = k1;
    if (k4 == 1) t2 = m - k2; else t2 = k2;
    if (t1 == t2) return; // reach to edge at the same time, aka a corner
    if (t1 < t2) dfs(k1 + k3 * t1, k2 + k4 * t1, -k3, k4, k5 + t1);
    else dfs(k1 + k3 * t2, k2 + k4 * t2, k3, -k4, k5 + t2);
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    fill(ans, ans + K, -1);
    REP(i, K) {
        scanf("%d%d", &x[i], &y[i]);
        va[x[i] + y[i]].push_back(i);
        vb[x[i] - y[i] + m].push_back(i);
    }
    dfs(0, 0, 1, 1, 0);
    REP(i, K) cout << ans[i] << endl;
    return 0;
}
