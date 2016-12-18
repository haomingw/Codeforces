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

const int maxn = 1010;
vector<int> g[maxn];
bool used[maxn];
int cnt = 0;

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    cnt++;
    for (int u : g[v]) dfs(u);
}

ll calc(int x) {
    return x * 1LL * (x - 1) / 2;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> gov;
    REP(i, k) {
        int c; cin >> c; c--;
        gov.push_back(c);
    }
    int u, v, rest = n, maxt = 0;
    REP(i, m) {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    for (int x : gov) {
        cnt = 0;
        dfs(x);
        ans += calc(cnt);
        rest -= cnt;
        maxt = max(maxt, cnt);
    }
    ans -= calc(maxt);
    ans += calc(rest + maxt);
    ans -= m;
    cout << ans << endl;
    return 0;
}
