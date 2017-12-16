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
vector<int> g[maxn];
int colors[maxn];

void dfs(int x, int col) {
    if (colors[x]) return;
    colors[x] = col + 1;
    for (int v : g[x]) {
        dfs(v, col ^ 1);
    }
}

int main() {
    int n;
    cin >> n;
    int u, v;
    vector<pii> cp;
    REP(i, n) {
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        g[2 * i].push_back(2 * i + 1);
        g[2 * i + 1].push_back(2 * i);
        cp.push_back(MP(u, v));
    }
    REP(i, 2 * n) {
        if (colors[i]) continue;
        dfs(i, 0);
    }
    for (auto& p : cp)
        cout << colors[p.first] << " " << colors[p.second] << endl;
    return 0;
}
