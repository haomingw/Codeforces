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

const int maxn = 2e5 + 5;
int dep[maxn], ans;
vector<int> g[maxn];

void dfs(int now, int parent) {
    dep[now] = (parent == 0) ? 0 : dep[parent] + 1;
    for (int son : g[now]) {
        if (son == parent) continue;
        dfs(son, now);
    }
}

void dfs2(int now, int parent, int depth) {
    if (depth >= dep[now]) return;
    ans = max(ans, dep[now]);
    for (int son : g[now]) {
        if (son == parent) continue;
        dfs2(son, now, depth + 1);
    }
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    int a, b;
    REP(i, n - 1) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(x, 0, 0);
    cout << ans * 2 << endl;
    return 0;
}
